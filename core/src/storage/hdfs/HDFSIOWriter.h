// Copyright (C) 2019-2020 Zilliz. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance
// with the License. You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software distributed under the License
// is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
// or implied. See the License for the specific language governing permissions and limitations under the License.

#pragma once

#include <memory>
#include <string>
#include "hdfs.h"
#include "storage/IOWriter.h"

namespace milvus {
namespace storage {

class HDFSIOWriter : public IOWriter {
 public:
    HDFSIOWriter() = default;
    ~HDFSIOWriter() = default;

    HDFSIOWriter(const HDFSIOWriter&) = delete;
    HDFSIOWriter(HDFSIOWriter&&) = delete;

    HDFSIOWriter&
    operator=(const HDFSIOWriter&) = delete;
    HDFSIOWriter&
    operator=(HDFSIOWriter&&) = delete;

    bool
    open(const std::string& name) override;

    void
    write(void* ptr, int64_t size) override;

    int64_t
    length() override;

    void
    close() override;

 public:
    int64_t len_;
    std::string name_;
};

}  // namespace storage
}  // namespace milvus