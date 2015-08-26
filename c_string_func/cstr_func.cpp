

//
int strlen(const char* str)
{
	assert(NULL != str);
	int len;
	while( (*str ++) != '\0') len++;
	return len;
}

//
int strcmp(const char* str1,const char* str2)
{
	assert(NULL != str1 && NULL!=str2);
	int ret =0;
	while((ret = *(unsigned char*)str1 - *(unsigned char*)str2) && *str1)
	{
		str1++;
		str2++;
	}
	if(ret<0) return -1;
	else if(ret>0) return 1;
	
	return ret;
}

//
char *strcat(char *strDest,const char* strSrc)
{
	char *address = strDest;
	assert(NULL!=strDest && NULL != strSrc);
	while(*strDest) strDest++;
	while(*strDest++ = *strSrc++);
	return address;
}

//
char* strcpy(char* strDest,const char* strSrc )
{
	assert(NULL!=strDest && NULL != strSrc);
	char *strD = strDest;
	while( (*strDest++ = *strSrc++) !='\0' );
	return strD;
}