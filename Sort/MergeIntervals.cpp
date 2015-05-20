Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

//先按照起始边从小到大进行排序

static bool compare(const Interval& a, const Interval& b)
{
	return a.start < b.start;
}

 vector<Interval> merge(vector<Interval>& intervals) 
{
    
	if(intervals.size()<=0)
		return intervals;
	sort(intervals.begin(),intervals.end(),compare);
    
	vector<Interval> result;
	result.push_back(intervals[0]);

	Interval temp =intervals[0]; 
	for(int i=1; i< intervals.size();i++)
	{
		if(intervals[i].start <= temp.end)
		{
			Interval interval(temp.start,max(temp.end,intervals[i].end));
			result.pop_back();
			result.push_back(interval);
			temp = interval;
		}else{
			 result.push_back(intervals[i]);
			 temp = intervals[i];
		}
	}

	return result;
}


