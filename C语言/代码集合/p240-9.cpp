/*************************************************************************
	> File Name: p240-9.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月20日 星期三 14时17分08秒
 ************************************************************************/

# include <iostream>
# include <string.h>
# include <queue>
# include <algorithm>
using namespace std;

struct state{//每一个状态
	int v[4];//三个杯子，下标从一开始
	int cnt;//当前步数
	bool operator <(const state& rhs) const{
		return cnt>rhs.cnt;
	}
};
priority_queue<state> q;//优先队列
int vis[160][160];//记录是否被访问过
int main(){
	int t, i, j, k, d;
	int cup[4];//三个杯子容量
	cin>>t;
	for(i=1; i<=t; i++){
		cin>>cup[1]>>cup[2]>>cup[3];
		if(cup[1]%2==1){//奇数没有办法均分
			printf("no\n");
			continue;
		}
		memset(vis, 0, sizeof(vis));
		while(!q.empty()){
			q.pop();
		}
		d=cup[1]/2;//目标
		struct state start;//开始状态
		start.v[1]=cup[1];
		start.v[2]=0;
		start.v[3]=0;
		start.cnt=0;
		vis[start.v[1]][start.v[2]]=vis[start.v[2]][start.v[1]]=1;//第一个状态标记为已经出现
		q.push(start);
		int flage=0;
		while(!q.empty()){
			struct state temp=q.top();
			q.pop();
			if(temp.v[1]==d||temp.v[2]==d||temp.v[3]==d){//到达目标
				printf("%d\n", temp.cnt+1);
				flage=1;
				break;
			}
			for(j=1; j<=3; j++){//从第j个杯子倒到第k个
				for(k=1; k<=3; k++){
					if(j!=k){
						if(temp.v[j]==0||temp.v[k]==cup[k]){//操作失败继续下一种策略
							continue;
						}
						else{
							struct state _temp;
							memcpy(&_temp, &temp, sizeof(temp));//备份一下，不能破坏temp
							int amount=min(cup[k], temp.v[j]+temp.v[k])-temp.v[k];//计算到水量
							_temp.v[j]=temp.v[j]-amount;//更新
							_temp.v[k]=temp.v[k]+amount;//更新
							
							_temp.cnt++;//更新
							if(vis[_temp.v[j]][_temp.v[k]]==0&&vis[_temp.v[k]][_temp.v[j]]==0){//找到新状态，入队
								q.push(_temp);
								vis[_temp.v[j]][_temp.v[k]]=vis[_temp.v[k]][_temp.v[j]]=1;
							}
						}
					}
				}
			}
		}
		if(!flage){//没找到
			printf("no\n");
		}
	}
	return 0;
}
