void merge_array(int *a, int *aux, int lo, int mid, int hi)
{
  int k;
  for (k = lo; k <= hi; k++)
    *(aux + k) = *(a + k);
  int i = lo, j = mid + 1;
  for (k = lo; k <= hi; k++)
  {
    if (i > mid)
      *(a + k) = *(aux + (j++));
    else if (j > hi)
      *(a + k) = *(aux + (i++));
    else if (*(aux + j) < *(aux + i))
      *(a + k) = *(aux + (j++));
    else
      *(a + k) = *(aux + (i++));
  }
}
void mergesort_recursivo(int *a, int *aux, int lo, int hi)
{
  if (hi <= lo)
    return;
  int mid = lo + (hi - lo) / 2;
  mergesort_recursivo(a, aux, lo, mid);
  mergesort_recursivo(a, aux, mid + 1, hi);
  if (*(a + (mid + 1)) >= *(a + mid))
    return; // improvement
  merge_array(a, aux, lo, mid, hi);
}

// the hi is the size of the array -1
void mergesort_run(int *a, int n, int lo, int hi)
{
  int *aux;
  aux = malloc(sizeof(int) * n);
  mergesort_recursivo(a, aux, lo, hi);
  free(aux);
}
