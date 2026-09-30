int ** convert(const int * t, size_t n, const size_t * lns, size_t rows)
{
  int ** arr = new int * [rows];
  size_t temp = 0;

  try
  {
    for (size_t i = 0; i < rows; ++i)
    {
      if (lns[i] > n - temp)
      {
        throw std::cerr << "Выход за пределы массива";
      }
      arr[i] = new int[lns[i]];
      for (size_t j = 0; j < lns[i]; ++j)
      {
        arr[i][j] = t[temp + j];
      }
      temp += lns[i];
    }
  }
  catch (...)
  {
    for (size_t i = 0; i < rows; ++i)
    {
      delete[] arr[i];
    }
    delete[] arr;
    throw;
  }

  return arr;
}
