int main()
{
  int n,q,l,r,k;
  cin>> n >> q;
  for(int i = 0;i < n;i++)
  {
    cin >> arr[i];
  }
  build(1,1,n);// 1 based indexing
  while(q--)
  {
    cin >> l >> r >> k;
    cout << query(1,1,n,l,r,k) << endl;
  }
}