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
#include <aws/elasticache/model/DescribeCacheParameterGroupsResult.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>

#include <utility>

using namespace Aws::ElastiCache::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils;
using namespace Aws;

DescribeCacheParameterGroupsResult::DescribeCacheParameterGroupsResult()
{
}

DescribeCacheParameterGroupsResult::DescribeCacheParameterGroupsResult(const AmazonWebServiceResult<XmlDocument>& result)
{
  *this = result;
}

DescribeCacheParameterGroupsResult& DescribeCacheParameterGroupsResult::operator =(const AmazonWebServiceResult<XmlDocument>& result)
{
  const XmlDocument& xmlDocument = result.GetPayload();
  XmlNode rootNode = xmlDocument.GetRootElement();
  XmlNode resultNode = rootNode.FirstChild("DescribeCacheParameterGroupsResult");

  if(!resultNode.IsNull())
  {
    XmlNode markerNode = resultNode.FirstChild("Marker");
    if(markerNode.IsNull())
    {
      markerNode = resultNode;
    }

    if(!markerNode.IsNull())
    {
      m_marker = StringUtils::Trim(markerNode.GetText().c_str());
    }
    XmlNode cacheParameterGroupsNode = resultNode.FirstChild("CacheParameterGroups");
    if(!cacheParameterGroupsNode.IsNull())
    {
      XmlNode cacheParameterGroupsMember = cacheParameterGroupsNode.FirstChild("CacheParameterGroup");
      while(!cacheParameterGroupsMember.IsNull())
      {
        m_cacheParameterGroups.push_back(cacheParameterGroupsMember);
        cacheParameterGroupsMember = cacheParameterGroupsMember.NextNode("CacheParameterGroup");
      }

    }
  }

  XmlNode responseMetadataNode = rootNode.FirstChild("ResponseMetadata");
  m_responseMetadata = responseMetadataNode;

  return *this;
}
