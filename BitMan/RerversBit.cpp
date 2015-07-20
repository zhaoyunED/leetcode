








//1
uint32_t reverseBits(uint32_t n)
{
        uint32_t m=0;
        for(int i=0;i<32;i++){
            m<<=1;
            m = m|(n & 1);//每次将二进制串的最后一位放到m的最后一位
            n>>=1;
        }
        return m;
}
//2
uint32_t reverseBits(uint32_t n)
{
    uint32_t bin=0;
    for (i = 0; i < 32; i++) 
         bin+=(n >> i & 1)<<(31-i);
    return bin;
}
//3
uint32_t reverseBits(uint32_t n)
{
        const int size = 32;
        bitset<size> bSet(n);
        for(int i=0; i < size/2; i++){
            int temp = bSet[i];
            bSet[i] = bSet[size - i - 1];
            bSet[size - i -1] = temp;
        }
        return (uint32_t) bSet.to_ulong();
}

//4 Lookup Table with O(1)
uint32_t reverseBits(uint32_t n)
{
    int rbitTable[256] = {
        #define R2(n) n, n + 2*64, n + 1 * 64, n + 3 * 64
        #define R4(n) R2(n), R2(n + 2 * 16), R2(n + 1 * 16), R2(n + 3 * 16)
        #define R6(n) R4(n), R4(n + 2 * 4), R4(n + 1 * 4), R4(n + 3 * 4)
        R6(0), R6(2), R6(1), R6(3)
    };
    uint32_t v;
    unsigned char *p = (unsigned char*)&n;
    unsigned char *q = (unsigned char*)&v;
    q[0] = rbitTable[p[3]];
    q[1] = rbitTable[p[2]];
    q[2] = rbitTable[p[1]];
    q[3] = rbitTable[p[0]];
    return v;
}

//5
uint32_t reverseBits(uint32_t n)
{
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
}


//6
//cache
private final Map<Byte, Integer> cache = new HashMap<Byte, Integer>();
public int reverseBits(int n) {
    byte[] bytes = new byte[4];
    for (int i = 0; i < 4; i++) // convert int into 4 bytes
        bytes[i] = (byte)((n >>> 8*i) & 0xFF);
    int result = 0;
    for (int i = 0; i < 4; i++) {
        result += reverseByte(bytes[i]); // reverse per byte
        if (i < 3)
            result <<= 8;
    }
    return result;
}

private int reverseByte(byte b) {
    Integer value = cache.get(b); // first look up from cache
    if (value != null)
        return value;
    value = 0;
    // reverse by bit
    for (int i = 0; i < 8; i++) {
        value += ((b >>> i) & 1);
        if (i < 7)
            value <<= 1;
    }
    cache.put(b, value);
    return value;
}