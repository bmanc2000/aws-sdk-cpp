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
#pragma once
#include <aws/email/SES_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSStreamFwd.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/email/model/ExtensionField.h>

namespace Aws
{
namespace Utils
{
namespace Xml
{
  class XmlNode;
} // namespace Xml
} // namespace Utils
namespace SES
{
namespace Model
{
  /*
    Message level DSN fields.
  */
  class AWS_SES_API MessageDsn
  {
  public:
    MessageDsn();
    MessageDsn(const Aws::Utils::Xml::XmlNode& xmlNode);
    MessageDsn& operator=(const Aws::Utils::Xml::XmlNode& xmlNode);

    void OutputToStream(Aws::OStream& ostream, const char* location, unsigned index, const char* locationValue) const;
    void OutputToStream(Aws::OStream& oStream, const char* location) const;

    /*
     The MTA that attempted to deliver the message. Should be RFC 3464 formatted to be "mta-name-type; mta-name" (e.g. "dns; foo.amazonses.com"). If not specified, "dns; inbound-smtp.[region].amazonaws.com" is used.
    */
    inline const Aws::String& GetReportingMta() const{ return m_reportingMta; }

    /*
     The MTA that attempted to deliver the message. Should be RFC 3464 formatted to be "mta-name-type; mta-name" (e.g. "dns; foo.amazonses.com"). If not specified, "dns; inbound-smtp.[region].amazonaws.com" is used.
    */
    inline void SetReportingMta(const Aws::String& value) { m_reportingMtaHasBeenSet = true; m_reportingMta = value; }

    /*
     The MTA that attempted to deliver the message. Should be RFC 3464 formatted to be "mta-name-type; mta-name" (e.g. "dns; foo.amazonses.com"). If not specified, "dns; inbound-smtp.[region].amazonaws.com" is used.
    */
    inline void SetReportingMta(Aws::String&& value) { m_reportingMtaHasBeenSet = true; m_reportingMta = value; }

    /*
     The MTA that attempted to deliver the message. Should be RFC 3464 formatted to be "mta-name-type; mta-name" (e.g. "dns; foo.amazonses.com"). If not specified, "dns; inbound-smtp.[region].amazonaws.com" is used.
    */
    inline void SetReportingMta(const char* value) { m_reportingMtaHasBeenSet = true; m_reportingMta.assign(value); }

    /*
     The MTA that attempted to deliver the message. Should be RFC 3464 formatted to be "mta-name-type; mta-name" (e.g. "dns; foo.amazonses.com"). If not specified, "dns; inbound-smtp.[region].amazonaws.com" is used.
    */
    inline MessageDsn& WithReportingMta(const Aws::String& value) { SetReportingMta(value); return *this;}

    /*
     The MTA that attempted to deliver the message. Should be RFC 3464 formatted to be "mta-name-type; mta-name" (e.g. "dns; foo.amazonses.com"). If not specified, "dns; inbound-smtp.[region].amazonaws.com" is used.
    */
    inline MessageDsn& WithReportingMta(Aws::String&& value) { SetReportingMta(value); return *this;}

    /*
     The MTA that attempted to deliver the message. Should be RFC 3464 formatted to be "mta-name-type; mta-name" (e.g. "dns; foo.amazonses.com"). If not specified, "dns; inbound-smtp.[region].amazonaws.com" is used.
    */
    inline MessageDsn& WithReportingMta(const char* value) { SetReportingMta(value); return *this;}

    /*
     When the message arrived at the Reporting MTA. This should be in RFC 822 date-time format if it's specified.
    */
    inline double GetArrivalDate() const{ return m_arrivalDate; }

    /*
     When the message arrived at the Reporting MTA. This should be in RFC 822 date-time format if it's specified.
    */
    inline void SetArrivalDate(double value) { m_arrivalDateHasBeenSet = true; m_arrivalDate = value; }

    /*
     When the message arrived at the Reporting MTA. This should be in RFC 822 date-time format if it's specified.
    */
    inline MessageDsn& WithArrivalDate(double value) { SetArrivalDate(value); return *this;}

    /*
     Additional x-headers to include in the DSN.
    */
    inline const Aws::Vector<ExtensionField>& GetExtensionFields() const{ return m_extensionFields; }

    /*
     Additional x-headers to include in the DSN.
    */
    inline void SetExtensionFields(const Aws::Vector<ExtensionField>& value) { m_extensionFieldsHasBeenSet = true; m_extensionFields = value; }

    /*
     Additional x-headers to include in the DSN.
    */
    inline void SetExtensionFields(Aws::Vector<ExtensionField>&& value) { m_extensionFieldsHasBeenSet = true; m_extensionFields = value; }

    /*
     Additional x-headers to include in the DSN.
    */
    inline MessageDsn& WithExtensionFields(const Aws::Vector<ExtensionField>& value) { SetExtensionFields(value); return *this;}

    /*
     Additional x-headers to include in the DSN.
    */
    inline MessageDsn& WithExtensionFields(Aws::Vector<ExtensionField>&& value) { SetExtensionFields(value); return *this;}

    /*
     Additional x-headers to include in the DSN.
    */
    inline MessageDsn& AddExtensionFields(const ExtensionField& value) { m_extensionFieldsHasBeenSet = true; m_extensionFields.push_back(value); return *this; }

    /*
     Additional x-headers to include in the DSN.
    */
    inline MessageDsn& AddExtensionFields(ExtensionField&& value) { m_extensionFieldsHasBeenSet = true; m_extensionFields.push_back(value); return *this; }

  private:
    Aws::String m_reportingMta;
    bool m_reportingMtaHasBeenSet;
    double m_arrivalDate;
    bool m_arrivalDateHasBeenSet;
    Aws::Vector<ExtensionField> m_extensionFields;
    bool m_extensionFieldsHasBeenSet;
  };

} // namespace Model
} // namespace SES
} // namespace Aws
