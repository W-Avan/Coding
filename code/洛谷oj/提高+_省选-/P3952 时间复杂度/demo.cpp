#include <bits/stdc++.h>
using namespace std;
string a, b;  //ѭ��ʹ��
int c, d, e, f[27], g[27], h, k, l[100], m, n, o;
/*
	c���м������ӣ�d����Ŀ���ĸ��Ӷ��Ƕ���
	e�ǵ�ǰ�ڼ���ѭ����f[]���жϱ����Ƿ�ʹ�ù�
	g[]�Ǵ���ÿ��ѭ���ı�����h�ǵ�ǰ���Ӷ��Ƕ���(��e��ͬ��
	k���ж���������Ƿ���У�l[]�Ǵ����Ǽ���ѭ�����˸��Ӷ�
	m�ǵ�ǰ����Ӷȣ�n�Ǵ���k=1ʱ��ѭ����
	o���������� 
*/ 
int main(){
	freopen("in.txt", "r", stdin);
	cin >> o;
	while(o--){
		c = 0, d = 0, e = 0, h = 0, k = 0, m = 0, n = 0;
		memset(f, 0, sizeof(f));
		memset(l, 0, sizeof(l));
		do{
			a = b;
			cin >> b;
		}while(b[0] != 'O');
		for(int i = 0; i < a.size(); i++)	c = c*10 + a[i] - '0';
		for(int i = 4; i < b.size()-1; i++)	d = d*10 + b[i] - '0';
		while(c > 0){
			c--;
			cin >> a;
			if(a[0] == 'F'){
				e++;
				cin >> a;
				if(f[a[0] - 'a'] == 1)	e = -1;
				else {
					f[a[0] - 'a'] = 1;
					g[e] = a[0] - 'a';
				}
				cin >> a >> b;
				if(a[0] != 'n' && b[0] == 'n' && k == 0){
					h++;
					l[e] = 1;
				}else if(((a.size() == b.size() && a > b) || (a.size() > b.size()) || (a[0] == 'n' && b[0] != 'n')) && k == 0){
					k = 1;
					n = e;
				}
			}else {
				m = max(m, h);
				f[g[e]] = 0;
				if(l[e] == 1){
					h--;
					l[e] = 0;
				}
				e--;
				if(n > 0 && e < n){
					k = 0;
					n = 0;
				}
			} 
			if(e == -1){
				cout << "ERR" << endl;
				c = -1;
			}
		}
		if(e > 0)	cout << "ERR" << endl;
		if(e == 0 && m == d)	cout << "Yes" << endl;
		if(e == 0 && m != d)	cout << "No" << endl;
	}
	return 0;
}
