There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next 
station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
        int i, j, n = gas.size();

        /*
         * If start from i, stop before station x -> no station k from i + 1 to x - 1 can reach x.
         * Bcoz if so, i can reach k and k can reach x, then i reaches x. Contradiction.
         * Thus i can jump directly to x instead of i + 1, bringing complexity from O(n^2) to O(n).
         */
        // start from station i
        for (i = 0; i < n; i += j) {
            int gas_left = 0;
            // forward j stations
            for (j = 1; j <= n; j++) {
                int k = (i + j - 1) % n;
                gas_left += gas[k] - cost[k];
                if (gas_left < 0)
                    break;
            }
            if (j > n)
                return i;
        }
        return -1;
}



int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
        int start = gas.size()-1;
        int end = 0;
       int sum = gas[start] - cost[start];
       while (start > end) {
          if (sum >= 0) {
             sum += gas[end] - cost[end];
             ++end;
          }
          else {
             --start;
             sum += gas[start] - cost[start];
          }
       }
       return sum >= 0 ? start : -1;
}