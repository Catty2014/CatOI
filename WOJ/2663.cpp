//卢本伟牛逼

#include <cstdio>
#include <algorithm>

using std::min;

const int N=2000233;

const int INF=2147483600;

int m,n;
int pos[N];
int poi[N];
int near[N];
int als[N];
int cnt;
int nrv,nrp=1;

/* void nearp() */
/* { */
/* 	printf("NEAR:"); */
/* 	for(int i=1;i<=n;i++) */
/* 	{ */
/* 		printf("%d ",near[i]); */
/* 	} */
/* 	printf("\n"); */
/* } */

void refresh_a(int posi)
{
	//printf("posi:%d\n",posi);
	near[posi]=0;
	nrv=-1;
	for(int j=posi+1; j<=n; j++)
	{
		if(near[j]<j-posi) break;
		near[j]=min(j-posi,near[j]);
//		if(near[j]>nrv)
//		{
//			nrv=near[j];
//			nrp=j;
//		}
	}
	for(int j=posi-1; j>=1; j--)
	{
		if(near[j]<posi-j) break;
		near[j]=min(posi-j,near[j]);
//		if(near[j]>nrv)
//		{
//			nrv=near[j];
//			nrp=j;
//		}
	}
	//nearp();
	for(int i=1;i<=n;i++)
	{
		if(near[i]>nrv)
		{
			nrv=near[i];
			nrp=i;
		}
	}
	return;
}

int ins(int nm)
{
	poi[nrp]=nm;
	pos[nm]=nrp;
	return nrp;
}

void refresh_r(int posi,int crr)
{
	poi[posi]=0;
	int _l,_r;
	for(int i=posi-1;i>=0;i--)
	{
		if(i==0)
		{
			_l=0;
		}
		if(poi[i]!=0)
		{
			_l=i;
			break;
		}
	}
	for(int i=posi+1;i<=n+1;i++)
	{
		if(i==n+1)
		{
			_r=n+1;
		}
		if(poi[i]!=0)
		{
			_r=i;
			break;
		}
	}
	//printf("RM:l=%d r=%d\n",_l,_r);
	if(_l==0&&_r==n+1)
	{
		for(int i=1;i<=n;i++)
		{
			near[i]=INF;
		}
	}
	for(int i=_l+1;i<=_r-1;i++)
	{
		near[i]=INF;
	}
	for(int i=_l+1;i>1&&i<_r;i++)
	{
		near[i]=i-_l;
	}
	for(int i=_r-1;i<n&&i>_l;i--)
	{
		if(near[i]<_r-i) break;
		near[i]=min(_r-i,near[i]);
	}
	//nearp();
	pos[crr]=0;
	for(int i=1;i<=n;i++)
	{
		if(near[i]>nrv)
		{
			nrv=near[i];
			nrp=i;
		}
	}
}


int main()
{
	freopen("tmp.in","r",stdin);
	freopen("tmp.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++)
	{
		near[i]=INF;
	}
	for(int i=1; i<=m; i++)
	{
		int op,cr;
		scanf("%d %d",&op,&cr);
		if(op==1)
		{
			++cnt;
			als[cr]=cnt;
			printf("%d\n",nrp);
			refresh_a(ins(cnt));
		}
		if(op==2)
		{
			int crr=als[cr];
			refresh_r(pos[crr],crr);
			
		}
	}
	return 0;
}
