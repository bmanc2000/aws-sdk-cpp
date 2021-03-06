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
#include <aws/cloudfront/model/Invalidation.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::CloudFront::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

Invalidation::Invalidation() : 
    m_idHasBeenSet(false),
    m_statusHasBeenSet(false),
    m_createTime(0.0),
    m_createTimeHasBeenSet(false),
    m_invalidationBatchHasBeenSet(false)
{
}

Invalidation::Invalidation(const XmlNode& xmlNode) : 
    m_idHasBeenSet(false),
    m_statusHasBeenSet(false),
    m_createTime(0.0),
    m_createTimeHasBeenSet(false),
    m_invalidationBatchHasBeenSet(false)
{
  *this = xmlNode;
}

Invalidation& Invalidation::operator =(const XmlNode& xmlNode)
{
  XmlNode resultNode = xmlNode;

  if(!resultNode.IsNull())
  {
    XmlNode idNode = resultNode.FirstChild("Id");
    if(idNode.IsNull())
    {
      idNode = resultNode;
    }

    if(!idNode.IsNull())
    {
      m_id = StringUtils::Trim(idNode.GetText().c_str());
      m_idHasBeenSet = true;
    }
    XmlNode statusNode = resultNode.FirstChild("Status");
    if(statusNode.IsNull())
    {
      statusNode = resultNode;
    }

    if(!statusNode.IsNull())
    {
      m_status = StringUtils::Trim(statusNode.GetText().c_str());
      m_statusHasBeenSet = true;
    }
    XmlNode createTimeNode = resultNode.FirstChild("CreateTime");
    if(createTimeNode.IsNull())
    {
      createTimeNode = resultNode;
    }

    if(!createTimeNode.IsNull())
    {
      m_createTime = StringUtils::ConvertToDouble(StringUtils::Trim(createTimeNode.GetText().c_str()).c_str());
      m_createTimeHasBeenSet = true;
    }
    XmlNode invalidationBatchNode = resultNode.FirstChild("InvalidationBatch");
    if(invalidationBatchNode.IsNull())
    {
      invalidationBatchNode = resultNode;
    }

    if(!invalidationBatchNode.IsNull())
    {
      m_invalidationBatch = invalidationBatchNode;
      m_invalidationBatchHasBeenSet = true;
    }
  }

  return *this;
}

void Invalidation::AddToNode(XmlNode& parentNode) const
{
  Aws::StringStream ss;
  if(m_idHasBeenSet)
  {
   XmlNode idNode = parentNode.CreateChildElement("Id");
   idNode.SetText(m_id);
  }

  if(m_statusHasBeenSet)
  {
   XmlNode statusNode = parentNode.CreateChildElement("Status");
   statusNode.SetText(m_status);
  }

  if(m_createTimeHasBeenSet)
  {
   XmlNode createTimeNode = parentNode.CreateChildElement("CreateTime");
  ss << m_createTime;
   createTimeNode.SetText(ss.str());
  ss.str("");
  }

  if(m_invalidationBatchHasBeenSet)
  {
   XmlNode invalidationBatchNode = parentNode.CreateChildElement("InvalidationBatch");
   m_invalidationBatch.AddToNode(invalidationBatchNode);
  }

}
