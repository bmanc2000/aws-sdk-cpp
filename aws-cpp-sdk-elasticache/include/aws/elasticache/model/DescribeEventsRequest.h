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
#include <aws/elasticache/ElastiCache_EXPORTS.h>
#include <aws/elasticache/ElastiCacheRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/elasticache/model/SourceType.h>

namespace Aws
{
namespace ElastiCache
{
namespace Model
{

  /*
    <p>Represents the input of a <i>DescribeEvents</i> action.</p>
  */
  class AWS_ELASTICACHE_API DescribeEventsRequest : public ElastiCacheRequest
  {
  public:
    DescribeEventsRequest();
    Aws::String SerializePayload() const override;


    /*
     <p>The identifier of the event source for which events will be returned. If not specified, then all sources are included in the response.</p>
    */
    inline const Aws::String& GetSourceIdentifier() const{ return m_sourceIdentifier; }

    /*
     <p>The identifier of the event source for which events will be returned. If not specified, then all sources are included in the response.</p>
    */
    inline void SetSourceIdentifier(const Aws::String& value) { m_sourceIdentifierHasBeenSet = true; m_sourceIdentifier = value; }

    /*
     <p>The identifier of the event source for which events will be returned. If not specified, then all sources are included in the response.</p>
    */
    inline void SetSourceIdentifier(Aws::String&& value) { m_sourceIdentifierHasBeenSet = true; m_sourceIdentifier = value; }

    /*
     <p>The identifier of the event source for which events will be returned. If not specified, then all sources are included in the response.</p>
    */
    inline void SetSourceIdentifier(const char* value) { m_sourceIdentifierHasBeenSet = true; m_sourceIdentifier.assign(value); }

    /*
     <p>The identifier of the event source for which events will be returned. If not specified, then all sources are included in the response.</p>
    */
    inline DescribeEventsRequest& WithSourceIdentifier(const Aws::String& value) { SetSourceIdentifier(value); return *this;}

    /*
     <p>The identifier of the event source for which events will be returned. If not specified, then all sources are included in the response.</p>
    */
    inline DescribeEventsRequest& WithSourceIdentifier(Aws::String&& value) { SetSourceIdentifier(value); return *this;}

    /*
     <p>The identifier of the event source for which events will be returned. If not specified, then all sources are included in the response.</p>
    */
    inline DescribeEventsRequest& WithSourceIdentifier(const char* value) { SetSourceIdentifier(value); return *this;}

    /*
     <p>The event source to retrieve events for. If no value is specified, all events are returned.</p> <p>Valid values are: <code>cache-cluster</code> | <code>cache-parameter-group</code> | <code>cache-security-group</code> | <code>cache-subnet-group</code></p>
    */
    inline const SourceType& GetSourceType() const{ return m_sourceType; }

    /*
     <p>The event source to retrieve events for. If no value is specified, all events are returned.</p> <p>Valid values are: <code>cache-cluster</code> | <code>cache-parameter-group</code> | <code>cache-security-group</code> | <code>cache-subnet-group</code></p>
    */
    inline void SetSourceType(const SourceType& value) { m_sourceTypeHasBeenSet = true; m_sourceType = value; }

    /*
     <p>The event source to retrieve events for. If no value is specified, all events are returned.</p> <p>Valid values are: <code>cache-cluster</code> | <code>cache-parameter-group</code> | <code>cache-security-group</code> | <code>cache-subnet-group</code></p>
    */
    inline void SetSourceType(SourceType&& value) { m_sourceTypeHasBeenSet = true; m_sourceType = value; }

    /*
     <p>The event source to retrieve events for. If no value is specified, all events are returned.</p> <p>Valid values are: <code>cache-cluster</code> | <code>cache-parameter-group</code> | <code>cache-security-group</code> | <code>cache-subnet-group</code></p>
    */
    inline DescribeEventsRequest& WithSourceType(const SourceType& value) { SetSourceType(value); return *this;}

    /*
     <p>The event source to retrieve events for. If no value is specified, all events are returned.</p> <p>Valid values are: <code>cache-cluster</code> | <code>cache-parameter-group</code> | <code>cache-security-group</code> | <code>cache-subnet-group</code></p>
    */
    inline DescribeEventsRequest& WithSourceType(SourceType&& value) { SetSourceType(value); return *this;}

    /*
     <p>The beginning of the time interval to retrieve events for, specified in ISO 8601 format.</p>
    */
    inline double GetStartTime() const{ return m_startTime; }

    /*
     <p>The beginning of the time interval to retrieve events for, specified in ISO 8601 format.</p>
    */
    inline void SetStartTime(double value) { m_startTimeHasBeenSet = true; m_startTime = value; }

    /*
     <p>The beginning of the time interval to retrieve events for, specified in ISO 8601 format.</p>
    */
    inline DescribeEventsRequest& WithStartTime(double value) { SetStartTime(value); return *this;}

    /*
     <p>The end of the time interval for which to retrieve events, specified in ISO 8601 format.</p>
    */
    inline double GetEndTime() const{ return m_endTime; }

    /*
     <p>The end of the time interval for which to retrieve events, specified in ISO 8601 format.</p>
    */
    inline void SetEndTime(double value) { m_endTimeHasBeenSet = true; m_endTime = value; }

    /*
     <p>The end of the time interval for which to retrieve events, specified in ISO 8601 format.</p>
    */
    inline DescribeEventsRequest& WithEndTime(double value) { SetEndTime(value); return *this;}

    /*
     <p>The number of minutes' worth of events to retrieve.</p>
    */
    inline long GetDuration() const{ return m_duration; }

    /*
     <p>The number of minutes' worth of events to retrieve.</p>
    */
    inline void SetDuration(long value) { m_durationHasBeenSet = true; m_duration = value; }

    /*
     <p>The number of minutes' worth of events to retrieve.</p>
    */
    inline DescribeEventsRequest& WithDuration(long value) { SetDuration(value); return *this;}

    /*
     <p>The maximum number of records to include in the response. If more records exist than the specified <code>MaxRecords</code> value, a marker is included in the response so that the remaining results can be retrieved.</p> <p>Default: 100</p> <p>Constraints: minimum 20; maximum 100.</p>
    */
    inline long GetMaxRecords() const{ return m_maxRecords; }

    /*
     <p>The maximum number of records to include in the response. If more records exist than the specified <code>MaxRecords</code> value, a marker is included in the response so that the remaining results can be retrieved.</p> <p>Default: 100</p> <p>Constraints: minimum 20; maximum 100.</p>
    */
    inline void SetMaxRecords(long value) { m_maxRecordsHasBeenSet = true; m_maxRecords = value; }

    /*
     <p>The maximum number of records to include in the response. If more records exist than the specified <code>MaxRecords</code> value, a marker is included in the response so that the remaining results can be retrieved.</p> <p>Default: 100</p> <p>Constraints: minimum 20; maximum 100.</p>
    */
    inline DescribeEventsRequest& WithMaxRecords(long value) { SetMaxRecords(value); return *this;}

    /*
     <p>An optional marker returned from a prior request. Use this marker for pagination of results from this action. If this parameter is specified, the response includes only records beyond the marker, up to the value specified by <i>MaxRecords</i>.</p>
    */
    inline const Aws::String& GetMarker() const{ return m_marker; }

    /*
     <p>An optional marker returned from a prior request. Use this marker for pagination of results from this action. If this parameter is specified, the response includes only records beyond the marker, up to the value specified by <i>MaxRecords</i>.</p>
    */
    inline void SetMarker(const Aws::String& value) { m_markerHasBeenSet = true; m_marker = value; }

    /*
     <p>An optional marker returned from a prior request. Use this marker for pagination of results from this action. If this parameter is specified, the response includes only records beyond the marker, up to the value specified by <i>MaxRecords</i>.</p>
    */
    inline void SetMarker(Aws::String&& value) { m_markerHasBeenSet = true; m_marker = value; }

    /*
     <p>An optional marker returned from a prior request. Use this marker for pagination of results from this action. If this parameter is specified, the response includes only records beyond the marker, up to the value specified by <i>MaxRecords</i>.</p>
    */
    inline void SetMarker(const char* value) { m_markerHasBeenSet = true; m_marker.assign(value); }

    /*
     <p>An optional marker returned from a prior request. Use this marker for pagination of results from this action. If this parameter is specified, the response includes only records beyond the marker, up to the value specified by <i>MaxRecords</i>.</p>
    */
    inline DescribeEventsRequest& WithMarker(const Aws::String& value) { SetMarker(value); return *this;}

    /*
     <p>An optional marker returned from a prior request. Use this marker for pagination of results from this action. If this parameter is specified, the response includes only records beyond the marker, up to the value specified by <i>MaxRecords</i>.</p>
    */
    inline DescribeEventsRequest& WithMarker(Aws::String&& value) { SetMarker(value); return *this;}

    /*
     <p>An optional marker returned from a prior request. Use this marker for pagination of results from this action. If this parameter is specified, the response includes only records beyond the marker, up to the value specified by <i>MaxRecords</i>.</p>
    */
    inline DescribeEventsRequest& WithMarker(const char* value) { SetMarker(value); return *this;}

  private:
    Aws::String m_sourceIdentifier;
    bool m_sourceIdentifierHasBeenSet;
    SourceType m_sourceType;
    bool m_sourceTypeHasBeenSet;
    double m_startTime;
    bool m_startTimeHasBeenSet;
    double m_endTime;
    bool m_endTimeHasBeenSet;
    long m_duration;
    bool m_durationHasBeenSet;
    long m_maxRecords;
    bool m_maxRecordsHasBeenSet;
    Aws::String m_marker;
    bool m_markerHasBeenSet;
  };

} // namespace Model
} // namespace ElastiCache
} // namespace Aws
