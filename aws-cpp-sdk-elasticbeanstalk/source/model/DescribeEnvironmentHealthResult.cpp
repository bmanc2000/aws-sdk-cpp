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
#include <aws/elasticbeanstalk/model/DescribeEnvironmentHealthResult.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>

#include <utility>

using namespace Aws::ElasticBeanstalk::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils;
using namespace Aws;

DescribeEnvironmentHealthResult::DescribeEnvironmentHealthResult() : 
    m_refreshedAt(0.0)
{
}

DescribeEnvironmentHealthResult::DescribeEnvironmentHealthResult(const AmazonWebServiceResult<XmlDocument>& result) : 
    m_refreshedAt(0.0)
{
  *this = result;
}

DescribeEnvironmentHealthResult& DescribeEnvironmentHealthResult::operator =(const AmazonWebServiceResult<XmlDocument>& result)
{
  const XmlDocument& xmlDocument = result.GetPayload();
  XmlNode rootNode = xmlDocument.GetRootElement();
  XmlNode resultNode = rootNode.FirstChild("DescribeEnvironmentHealthResult");

  if(!resultNode.IsNull())
  {
    XmlNode environmentNameNode = resultNode.FirstChild("EnvironmentName");
    if(environmentNameNode.IsNull())
    {
      environmentNameNode = resultNode;
    }

    if(!environmentNameNode.IsNull())
    {
      m_environmentName = StringUtils::Trim(environmentNameNode.GetText().c_str());
    }
    XmlNode healthStatusNode = resultNode.FirstChild("HealthStatus");
    if(healthStatusNode.IsNull())
    {
      healthStatusNode = resultNode;
    }

    if(!healthStatusNode.IsNull())
    {
      m_healthStatus = StringUtils::Trim(healthStatusNode.GetText().c_str());
    }
    XmlNode statusNode = resultNode.FirstChild("Status");
    if(statusNode.IsNull())
    {
      statusNode = resultNode;
    }

    if(!statusNode.IsNull())
    {
      m_status = EnvironmentHealthMapper::GetEnvironmentHealthForName(StringUtils::Trim(statusNode.GetText().c_str()).c_str());
    }
    XmlNode colorNode = resultNode.FirstChild("Color");
    if(colorNode.IsNull())
    {
      colorNode = resultNode;
    }

    if(!colorNode.IsNull())
    {
      m_color = StringUtils::Trim(colorNode.GetText().c_str());
    }
    XmlNode causesNode = resultNode.FirstChild("Causes");
    if(!causesNode.IsNull())
    {
      XmlNode causesMember = causesNode.FirstChild("member");
      while(!causesMember.IsNull())
      {
        m_causes.push_back(StringUtils::Trim(causesMember.GetText().c_str()));
        causesMember = causesMember.NextNode("member");
      }

    }
    XmlNode applicationMetricsNode = resultNode.FirstChild("ApplicationMetrics");
    if(applicationMetricsNode.IsNull())
    {
      applicationMetricsNode = resultNode;
    }

    if(!applicationMetricsNode.IsNull())
    {
      m_applicationMetrics = applicationMetricsNode;
    }
    XmlNode instancesHealthNode = resultNode.FirstChild("InstancesHealth");
    if(instancesHealthNode.IsNull())
    {
      instancesHealthNode = resultNode;
    }

    if(!instancesHealthNode.IsNull())
    {
      m_instancesHealth = instancesHealthNode;
    }
    XmlNode refreshedAtNode = resultNode.FirstChild("RefreshedAt");
    if(refreshedAtNode.IsNull())
    {
      refreshedAtNode = resultNode;
    }

    if(!refreshedAtNode.IsNull())
    {
      m_refreshedAt = StringUtils::ConvertToDouble(StringUtils::Trim(refreshedAtNode.GetText().c_str()).c_str());
    }
  }

  XmlNode responseMetadataNode = rootNode.FirstChild("ResponseMetadata");
  m_responseMetadata = responseMetadataNode;

  return *this;
}
