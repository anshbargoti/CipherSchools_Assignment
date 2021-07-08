class petrolPump
{
    public:
    int petrol;
    int distance;
};

class Solution {
public:
    int circularTour(vector<petrolPump> vc) 
    { 
        int st = 0; 
        int ext=0;
        int l = 0;
        int n = vc.size();

        for(int i = 0; i < n; i++)
        {
            ext += vc[i].petrol - vc[i].distance;
            if(ext < 0)
            {
                st = i + 1;
                l += abs(ext);
                ext = 0;
            }
        }

        if(ext - l >= 0)
            return st;
        else
            return -1;
    } 
};