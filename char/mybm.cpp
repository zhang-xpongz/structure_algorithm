#include <iostream>
#include <vector>
using namespace std;

void generateBC(const char *sub, int subLen, vector<int> &bc)
{
	for(int i=0;i < subLen; i++)
	{
		bc[sub[i]] = i;
	}
}

void generateGS(const char *sub, int subLen, vector<int>&suffix, vector<bool>&prefix)
{
    for(int i = 0; i < subLen-1; i++)
    {
        int j = i;
        int k = 0;
        while(j >=0 && sub[i] == sub[subLen - 1 - k])
        {
            j--;
            k++;
            suffix[k] = i;
        }

        if(j == -1)
        {
            prefix[k] = true;
        }
    }
}

int moveByGS(int j, int subLen, vector<int>&suffix, vector<bool>&prefix)
{
    int len = subLen - 1 - j;
    if(suffix[len] > -1)
        return (j - suffix[len] +1);
    for(int r =j+2; r <= subLen; r++ )
    {
        if(prefix[subLen - r])
            return r;
    }
    return subLen;
}

int bm(const char *m, int mLen, const char *sub, int subLen)
{
    vector<int> bc(256, -1);
    generateBC(sub, subLen, bc);
    vector<int>suffix(subLen, -1);
    vector<bool>prefix(subLen, false);

    for(int i = 0; i <= mLen - subLen;)
    {
        int j = subLen - 1;
        while(j >=0 && m[i+j] == sub[j])
        {
            j--;
        }

        if(j == -1)
            return i;

        int x = j - bc[m[i+j]];
        int y = 0;
        if(j < subLen - 1)
        {
            y = moveByGS(j, subLen, suffix, prefix);
        }

        if(x < y)
        {
            i+=y;
        }
        else
        {
            i+=x;
        }
    }
    return -1;
}
int main()
{
   //string main_s="afdskdfjksdjkjfksjfafdeafdadfdf";
   //string sub="afdeafd";
   string main_s = "afsdfgdf";
   string sub="gdf";
   int i = bm(main_s.c_str(), main_s.size(), sub.c_str(), sub.size());
   cout << i << endl;
}
