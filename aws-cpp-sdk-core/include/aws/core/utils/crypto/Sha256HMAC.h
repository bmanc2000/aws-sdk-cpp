/*
  * Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
  * 
  * Licensed under the Apache License, Version 2.0 (the "License").
  * You may not use this file except in compliance with the License.
  * A copy of the License is located at
  * 
  *  http://aws.amazon.com/apache2.0
  * 
  * or in the "license" file accompanying this file. This file is distributed
  * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
  * express or implied. See the License for the specific language governing
  * permissions and limitations under the License.
  */

/*
* Interface for Sha256 encryptor and hmac
*/
#pragma once

#ifdef __APPLE__

#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#endif // __APPLE__

#include <aws/core/Core_EXPORTS.h>

#include <aws/core/utils/crypto/HMAC.h>
#include <aws/core/utils/memory/AWSMemory.h>

namespace Aws
{
namespace Utils
{
namespace Crypto
{

class WindowsHashImpl;

class AWS_CORE_API Sha256HMAC : public HMAC
{
    public:

        Sha256HMAC();
        virtual ~Sha256HMAC();

        /**
        * Calculates a SHA256 HMAC digest (not hex encoded)
        */
        virtual HashResult Calculate(const ByteBuffer& toSign, const ByteBuffer& secret) override;

    private:

        #if defined(_WINDOWS) || defined(__MINGW32__) || defined(__MINGW64__)
            Aws::UniquePtr< WindowsHashImpl > m_windowsImpl;
        #endif
};

} // namespace Sha256
} // namespace Utils
} // namespace Aws

