string uint32_to_ip(uint32_t ip)
{
  //char *bits = reinterpret_cast<char*>(&ip);
  unsigned int res[4];
  for (int i = 0; i < 4; i++)
    res[i] = (int) static_cast<unsigned char>(ip >> (i*8));
  string result = "";
  for (int j = 3; j >= 0; j--) {
    result += to_string(res[j]);
    if (j > 0)
        result.push_back('.');
  }
  return result;
}