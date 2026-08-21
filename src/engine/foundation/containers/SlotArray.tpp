/*
    SlotArray.tpp

    Template implementation of a handle/slot buffer for run-time resource management.
*/

#include <utility>

namespace toxico {
    template<typename T, Handle H>
    template<typename... Args>
    std::pair<H, T*> SlotArray<T, H>::create(Args&& ...args) {
        // Fetch a valid index
        uint32_t index = slots_.size();
        if (!free_list_.empty()) {
            index = free_list_.back();
            free_list_.pop_back();
        }

        // Add a new slot if needed
        if (index == slots_.size())
            slots_.push_back(Slot{});

        // Create a new item
        auto& slot = slots_[index];
        slot.object = std::make_unique<T>(std::forward<Args>(args)...);
        auto* object_ptr = slot.object.get();

        // Create a handle for this slot
        H handle(
            index,
            slot.generation
        );

        // Return handle and created object
        return {handle, object_ptr};
    }

    template<typename T, Handle H>
    void SlotArray<T, H>::destroy(H handle) {
        // Ignore invalid handles
        auto* object = resolve(handle);
        if (!object)
            return;

        // Fetch the slot being freed
        auto index = handle.index();
        auto& slot = slots_[index];

        // Free slot memory
        ++(slot.generation);
        if (slot.object)
            slot.object.reset();
        
        // Free index for future use
        free_list_.push_back(index);
    }

    template<typename T, Handle H>
    const T* SlotArray<T, H>::resolve(H handle) const {
        // Handle is invalid
        if (handle.index() >= slots_.size())
            return nullptr;

        // Fetch slot by handle index
        auto& slot = slots_[handle.index()];

        // Invalidate slots on generation mismatch
        if (slot.generation != handle.generation())
            return nullptr;

        // Return the value
        return slot.object.get();
    }

    template<typename T, Handle H>
    T* SlotArray<T, H>::resolve(H handle) {
        return const_cast<T*>(
            std::as_const(*this).resolve(handle)
        );
    }

    template<typename T, Handle H>
    bool SlotArray<T, H>::isValid(H handle) const {
        return resolve(handle) != nullptr;
    }
}
