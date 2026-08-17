/*
    FileBase.hpp

    Declaration of an abstract file object.
*/

#pragma once

#include "platform/interfaces/IFile.hpp"

namespace toxico {
    class FileBase : public IFile {
    private:
        FileOpenMode open_mode_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param open_mode The file open mode.
         */
        FileBase(FileOpenMode open_mode);

        /**
         * @brief Gets the open mode for the file.
         * 
         * @return The open mode for the file.
         */
        FileOpenMode openMode() const final;

        /**
         * @brief Gets if the file can be read from.
         * 
         * @returns The read state of the file.
         */
        bool canRead() const final;

        /**
         * @brief Gets if the file can be written to.
         * 
         * @returns The write state of the file.
         */
        bool canWrite() const final;
    };
}
