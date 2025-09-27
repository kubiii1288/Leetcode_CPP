//
// Created by Anh Le on 9/19/25.
//

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int sum_gas = 0;
    int sum_cost = 0;
    int energy = 0;
    int ans = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        sum_gas += gas[i];
        sum_cost += cost[i];
        energy += (gas[i] - cost[i]);
        if (energy < 0)
        {
            energy = 0;
            ans = i + 1;
        }
    }
    if (sum_gas < sum_cost) return -1;
    return ans;
}
