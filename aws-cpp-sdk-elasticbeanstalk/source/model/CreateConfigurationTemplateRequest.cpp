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
#include <aws/elasticbeanstalk/model/CreateConfigurationTemplateRequest.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

using namespace Aws::ElasticBeanstalk::Model;
using namespace Aws::Utils;

CreateConfigurationTemplateRequest::CreateConfigurationTemplateRequest() : 
    m_applicationNameHasBeenSet(false),
    m_templateNameHasBeenSet(false),
    m_solutionStackNameHasBeenSet(false),
    m_sourceConfigurationHasBeenSet(false),
    m_environmentIdHasBeenSet(false),
    m_descriptionHasBeenSet(false),
    m_optionSettingsHasBeenSet(false)
{
}

Aws::String CreateConfigurationTemplateRequest::SerializePayload() const
{
  Aws::StringStream ss;
  ss << "Action=CreateConfigurationTemplate&";
  if(m_applicationNameHasBeenSet)
  {
    ss << "ApplicationName=" << StringUtils::URLEncode(m_applicationName.c_str()) << "&";
  }
  if(m_templateNameHasBeenSet)
  {
    ss << "TemplateName=" << StringUtils::URLEncode(m_templateName.c_str()) << "&";
  }
  if(m_solutionStackNameHasBeenSet)
  {
    ss << "SolutionStackName=" << StringUtils::URLEncode(m_solutionStackName.c_str()) << "&";
  }
  if(m_sourceConfigurationHasBeenSet)
  {
    m_sourceConfiguration.OutputToStream(ss, "SourceConfiguration.");
  }
  if(m_environmentIdHasBeenSet)
  {
    ss << "EnvironmentId=" << StringUtils::URLEncode(m_environmentId.c_str()) << "&";
  }
  if(m_descriptionHasBeenSet)
  {
    ss << "Description=" << StringUtils::URLEncode(m_description.c_str()) << "&";
  }
  if(m_optionSettingsHasBeenSet)
  {
    unsigned optionSettingsCount = 1;
    for(auto& item : m_optionSettings)
    {
      item.OutputToStream(ss, "OptionSettings.member.", optionSettingsCount, "");
      optionSettingsCount++;
    }
  }
  ss << "Version=2010-12-01";
  return ss.str();
}

