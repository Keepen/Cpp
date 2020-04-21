//����������
/*�� n ����Ʒ��һ����СΪ m �ı���.�������� A ��ʾÿ����Ʒ�Ĵ�С������ V ��ʾÿ����Ʒ�ļ�ֵ.
�ʶ���װ�뱳�����ܼ�ֵ�Ƕ�� */

//������
//1.����״̬��F[i][j] -- ������СΪj��װǰi����Ʒ������ֵ
//2.����ÿһ��������˵��Ҫô�ţ�Ҫô����
//		�ţ�F[i][j] = F[i - 1][j]
//	  ���ţ�
//		1�����ţ�	F[i][j] = F[i - 1][j] + V[i]
//		2�������ţ�	F[i][j] = F[i - 1][j - A[i]] + V[i]
//	  ����ʱ������ֵ���� 1)�� 2���еĽϴ�ֵ
//	F[i][j] ���Ƿ��벻���еĽϴ���
//3.������ֵ����F[n][m]




#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	/**
	* @param m: An integer m denotes the size of a backpack
	* @param A: Given n items with size A[i]
	* @param V: Given n items with value V[i]
	* @return: The maximum value
	*/
	int backPackII(int m, vector<int> &A, vector<int> &V) {
		// write your code here
		int num = (int)A.size();
		vector<vector<int>> dp(m + 1, vector<int>(num + 1, 0));
		for (int i = 1; i <= num; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (A[i] <= j) {
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - A[i]]) + V[i];
				}
			}
		}
		return dp[num][m];
	}
};

//�Ż���
//�ռ临�Ӷȿ��Լ�ΪO(M) -- һά���飬
//ע�⣺һά����ʱ����Ҫ�Ӻ���ǰ���и�ֵ������Ḳ�ǡ�




int main() {

	system("pause");
	return 0;
}