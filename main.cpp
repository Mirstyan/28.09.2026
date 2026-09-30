#include <iostream>
#include <new>

void rmMtx(int ** mtx, size_t m);

int ** makeMtx(size_t m, size_t n)
{
  int ** mtxR = new int * [m];

  try
  {
    for (size_t i = 0; i < m; ++i)
    {
      mtxR[i] = new int [n];
    }
  }
  catch (const std::bad_alloc & e)
  {
    rmMtx(mtxR, m);
    throw;
  }

  return mtxR;
}


void rmMtx(int ** mtx, size_t m)
{
  for (size_t i = 0; i < m; ++i)
  {
    delete [] mtx[i];
  }

  delete [] mtx;
}

int ** transpose(int ** mtx, size_t m, size_t n)
{
  int ** transposed = makeMtx(n, m);
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      transposed[j][i] = mtx[i][j];
    }
  }

  return transposed;
}


void printMtx(int ** mtx, size_t m, size_t n)
{
  for (size_t i = 0; i < n; ++i)
  {
    for (size_t j = 0; j < m; ++j)
    {
      if (j != 0)
      {
        std::cout << ' ';
      }
      std::cout << mtx[i][j];
    }
    std::cout << '\n';
  }
}

int main()
{
  size_t m = 0;
  size_t n = 0;
  std::cin >> m >> n;
  if (!std::cin || m == 0 || n == 0)
  {
    return 1;
  }

  int ** mtx = nullptr;
  mtx = makeMtx(m, n);
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      std::cin >> mtx[i][j];
    }
  }

  if (std::cin.fail())
  {
    rmMtx(mtx, m);
    return 1;
  }

  int ** transposed = transpose(mtx, m, n);
  rmMtx(mtx, m);

  printMtx(transposed, m, n);

  rmMtx(transposed, n);
}


