#include<iostream>
using namespace std;
int max(int a, int b)//ȡ���ֵ����
{
    return a > b ? a : b;
}

struct Thing
{
    int w;
    int v;
}list[101];

int dp[101][1001];

int main()
{
    int s, n;//������������Ʒ����
    cin >> s >> n;
        for (int i = 1; i <= n; i++)
        {
           cin>>list[i].w>>list[i].v;//����ÿ����Ʒ������ͼ�ֵ
        }
        for (int i = 0; i <= s; i++) dp[0][i] = 0;//��ʼ����ά����
        for (int i = 1; i <= n; i++)//ѭ��ÿ����Ʒ��ִ��״̬ת�Ʒ���
        {
            for (int j = s; j >= list[i].w; j--)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - list[i].w] + list[i].v);
            }
            for (int j = list[i].w - 1; j >= 0; j--)
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
        cout<<dp[n][s];
    return 0;
}