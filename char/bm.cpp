#include <iostream>
#include <vector>
using namespace std;

void generateGS(const char *sub, int subLen, vector<int> &suffix, vector<bool> &prefix)
{
    for(int i =0; i< subLen - 1; ++i)
    {
        int j = i;
        int k = 0;
        while(j >=0 && sub[j] == sub[subLen-1-k])
        {
            --j;
            ++k;
            suffix[k] = j+1;
        }
        if(j==-1)
            prefix[k] = true;
    }
    return;
}

void generateBC(const char *sub, int subLen, vector<int> &bc)
{
    for(int i = 0; i< subLen; i++)
    {
        bc[sub[i]] = i;
    }
}

int moveByGS(int k, int subLen, vector<int> &suffix, vector<bool> &prefix)
{
    int len = subLen - 1 - k;
    if(suffix[len] > -1)
        return (k-suffix[len]+1);

    for(int r = k+2; r <= subLen-1; r++)
    {
        if(prefix[subLen-r] == true)
            return r;
    }

    return subLen;
}

int bm(const char *main_s, int mLen, const char *sub, int subLen)
{
    cout << "mainsize:" << mLen <<endl;
    cout << "subSize:" << subLen <<endl;

    if(subLen > mLen)
        return -1;

    vector<int>bc(256, -1);
    generateBC(sub, subLen, bc); //创建BadChar hash表
    cout << "BC "<<endl;
    vector<int>suffix(subLen, -1);
    vector<bool>prefix(subLen, false);

    generateGS(sub, subLen, suffix, prefix); //创建最好后缀字串的下表和是否是前缀子串
    cout << "GS"<<endl;
    for(int i=0; i<= mLen - subLen;)// 遍历主串
    {
        int j = subLen - 1;
        while(j>=0) //从右端遍历模版串
        {
            if(main_s[i+j] == sub[j])
            {
                j--;
            }
            else
            {
                break;
            }
        }
        if(j < 0)
            return i;

        int x = j-bc[main_s[i+j]];//坏字符滑动

        int y = 0;
        if(j < subLen-1)//有好后缀
        {
            y =  moveByGS(j, subLen, suffix, prefix);
        }

        cout <<"x:"<< x << "y:"<< y <<endl;

        if(x < y)
        {
            i = i+y;
        }
        else
        {
            i = i+x;
        }
    }
    return -1;
}

int main()
{
    string main_s="afdskdfjksdjkjfksjfafdeafdadfdf";
    string sub="afdeafd";

    int i = bm(main_s.c_str(), main_s.size(), sub.c_str(), sub.size());
    cout << i << endl;
#if 0
    vector<int>bc(256, -1);
    vector<int> suffix(7, -1);
    vector<bool> prefix(7);

    generateGS(sub.c_str(), 7, suffix, prefix);
    cout << sub <<endl;
    for(auto iter = suffix.begin(); iter != suffix.end(); iter++)
    {
        cout << *iter << endl;
    }
    cout << "*******************"<<endl;
    for(auto iter = prefix.begin(); iter != prefix.end(); iter++)
    {
        cout << *iter <<endl;
    }
#endif
}
