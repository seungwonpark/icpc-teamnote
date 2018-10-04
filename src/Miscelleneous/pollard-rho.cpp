// 3,215,031,751
// ll p[] = {2,3,5,7};
// 3,825,123,056,546,413,051
ll p[]={2,3,5,7,11,13,17,19,23};

ll sqa(ll a,ll b,ll c){
  ll ret = 1;
  while(b){
    if(b&1)ret=(__int128)ret*a%c;
    a=(__int128)a*a%c;
    b>>=1;
  }
  return ret;
}

bool ML(ll x)
{
  if(x==2)return true;
  if(x<2||!(x&1))return false;
  ll y = x-1;
  int s = 0;
  while((y&1)==0)y>>=1,s++;
  for(ll c : p){
    if(c>=x)return true;
    ll d = sqa(c,y,x);
    if(d==1)continue;
    for(int j=0;j<s;j++){
      ll t = (__int128)d*d%x;
      if(t==1 && d!=1 && d!=x-1)return false;
      d = t;
    }
    if(d!=1)return false;
  }
  return true;
}

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

ll div(ll x)
{
  ll a=rand()%(x-1)+1,b=a,i=1,k=2;
  ll c=1;
  do{
    i++;
    ll d = gcd(b-a+x,x);
    if(d!=1 && d!=x)return d;
    if(i==k)b=a,k<<=1;
    a=((__int128)a*a+x-c)%x;
  }while(a!=b);
  return x;
}

void PR(ll x)
{
  if(x==1)return;
  if(ML(x)){/* x is prime factor */printf("%lld\n", x);return;}
  ll p = div(x);
  PR(x/p);
  PR(p);
}
