#pragma once

/*
 *  Copyright(c) 2020 Jeremiah van Oosten
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files(the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions :
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 *  IN THE SOFTWARE.
 */

/**
 *  @file IndexBufferView.h
 *  @date October 17, 2020
 *  @author Jeremiah van Oosten
 *
 *  @brief Wrapper for an Index Buffer View.
 */

#include <d3d12.h>  // For D3D12_INDEX_BUFFER_VIEW
#include <memory> // For std::shared_ptr

namespace dx12lib
{

class Device;
class IndexBuffer;

class IndexBufferView
{
public:
    std::shared_ptr<IndexBuffer> GetIndexBuffer() const
    {
        return m_IndexBuffer;
    }

    D3D12_INDEX_BUFFER_VIEW GetIndexBufferView() const
    {
        return m_IndexBufferView;
    }

protected:
    IndexBufferView( Device& device, std::shared_ptr<IndexBuffer> indexBuffer );
    virtual ~IndexBufferView() = default;

private:
    Device&                      m_Device;
    std::shared_ptr<IndexBuffer> m_IndexBuffer;
    D3D12_INDEX_BUFFER_VIEW      m_IndexBufferView;
};

}  // namespace dx12lib
