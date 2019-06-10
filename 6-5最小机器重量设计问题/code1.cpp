#include<fstream>
#include<queue>

//#define _DEBUG_
const int MAXN=23;
const int MAXNUM=(1<<30);
int soC[MAXN][MAXN],soW[MAXN][MAXN];

std::ifstream fin("input.txt");
std::ofstream fo("output.txt");

class ResNode
{
  private:
    unsigned char rv[MAXN];
  public:
    
    int weight,weightMin;
    int deep;
    int n;
    int cost,costMin;
    void print()
    {
    #ifdef _DEBUG_
      fo<<"dp"<<deep<<" c"<<cost<<" w"<<weight<<" mw"<<weightMin<<" mc"<<costMin<<"\n";
    #endif
      fo<<weight<<std::endl;
      //fo<<int(rv[0])+1;
      int i=0;
      for(i=0;i<n-1;i++)
      {
        fo<<int(rv[i])+1<<" ";
      }
      fo<<int(rv[i])+1<<'\n';
    }
    void add(int v)
    {
//      rv.push_back(v);
      deep+=1;
      rv[deep]=v;
      weight+=soW[deep][v];
      cost+=soC[deep][v];
    }
    ResNode(int _n)
    {
      n=_n;
      for(int i=0;i<n;i++)
      {
        rv[i]=0;
      }
      cost=0;
      weight=0;
      deep=0;
      weightMin=0;
      costMin=0;
    }
    bool operator < (const ResNode &a) const 
    {  
      return weightMin>a.weightMin;//min first
    }

};
int max(int a,int b)
{
  if(a>b)return a;
  else return b;
}
int min(int a,int b)
{
  if(a<b)return a;
  else return b;
}
class Solver
{
  public:
    int n,m,d;

    std::priority_queue<ResNode>que;
    int minAllc[MAXN+1];
    int minAllw[MAXN+1];
    void proc()
    {
      while(!que.empty())
      {
        que.pop();
      }
      ResNode rn(n);
      rn.deep=-1;
      que.push(rn);
      rn.weight=(MAXNUM);
      rn.cost=(MAXNUM);
      rn.weightMin=(MAXNUM);
      rn.costMin=(MAXNUM);
      ResNode best=rn;
      int maxAllc=0;

      for(int i=0;i<n+1;i++)
      {
        minAllc[i]=0;
        minAllw[i]=0;
      }
      for(int i=0;i<n;i++)
      {
        int maxC=0;
        int minC=MAXNUM;
        int minW=MAXNUM;
        for(int j=0;j<m;j++)
        {
          maxC=max(maxC,soC[i][j]);
          minC=min(minC,soC[i][j]);
          minW=min(minW,soW[i][j]);
        }
        #ifdef _DEBUG_
        fo<<maxC<<"  "<<minC<<"  "<<minW<<std::endl;
        #endif
        maxAllc+=maxC;
        for(int j=0;j<i+1;j++)
        {
          minAllc[j]+=minC;
          minAllw[j]+=minW;
        }
      }
      
      if(maxAllc<=d)
      {
        fo<<minAllw[0]<<std::endl;
        int i;
        for(i=0;i<n-1;i++)
        {
          int minW=MAXNUM;
          int minI=0;
          for(int j=0;j<m;j++)
          {
            if(soW[i][j]<minW)
            {
              minW=soW[i][j];
              minI=j;
            }
          }
          fo<<minI+1<<" ";

        }
        int minW=MAXNUM;
        int minI=0;
        for(int j=0;j<m;j++)
        {
          if(soW[i][j]<minW)
          {
            minW=soW[i][j];
            minI=j;
          }
        }
        fo<<minI+1<<'\n';
        return ; 
      }

      while(!que.empty())
      {

        ResNode rncur=que.top();
        que.pop();

        if(rncur.deep==n-1)
        {
          
          if(rncur.cost<=d&&
          ((rncur.weight<=best.weight&&rncur.cost<best.cost)||
          (rncur.weight<best.weight&&rncur.cost<=best.cost)))
          {
            //fo<<"best";
            best=rncur;
          }
          #ifdef _DEBUG_
          rncur.print();
          #endif
        }else
        {
          #ifdef _DEBUG_
          rncur.print();
          #endif
          /*
          if(rncur.weightMin>best.weight||rncur.costMin>d)
          {
            continue;
          }*/
          for(int i=0;i<m;i++)
          {
            ResNode r=rncur;
            r.add(i);
            calWeightMin(r);
            if(r.weightMin>best.weight||r.costMin>d)
            {
              continue;
            }else
            {
              que.push(r);
            }
          }
        }
      }
      best.print();
    }
    
    void calWeightMin(ResNode &rn)
    {
      rn.weightMin=rn.weight;
      rn.costMin=rn.cost;
      rn.weightMin+=minAllw[rn.deep+1];
      rn.costMin+=minAllc[rn.deep+1];
      
      /*
      for(int i=rn.deep+1;i<n;i++)
      {
        int minW=MAXNUM;
        int minC=MAXNUM;
        for(int j=0;j<m;j++)
        {
          if(soW[i][j]<minW)
          {
            minW=soW[i][j];
          }
          if(soC[i][j]<minC)
          {
            minC=soC[i][j];
          }
        }
        rn.weightMin+=minW;
        rn.costMin+=minC;
        
      }*/
      #ifdef _DEBUG_
      fo<<rn.weightMin<<"  "<<rn.costMin<<minAllw[rn.deep+1]<<"  "<<minAllc[rn.deep+1]<<"  "<<std::endl;
      #endif
      //fo<<rn.weightMin<<'H'<<rn.costMin<<'H';
    }
};


int main()
{

  
  int nn,mm,dd;
  while(fin>>nn>>mm>>dd)
  {
    Solver so;
    so.n=nn;
    so.m=mm;
    so.d=dd;
    for(int i=0;i<so.n;i++)
    {
      for(int j=0;j<so.m;j++)
      {
        fin>>soC[i][j];
      }
    }
    for(int i=0;i<so.n;i++)
    {
      for(int j=0;j<so.m;j++)
      {
        fin>>soW[i][j];
      }
    }
    so.proc();
  }
  return 0;
}