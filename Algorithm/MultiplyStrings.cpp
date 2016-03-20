/*
 * Copyright (C) 2016  Mewiteor <mewiteor@hotmail.com>
 * 
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

/*
 * Given two numbers represented as strings, return multiplication
 * of the numbers as a string.
 *
 * Note: The numbers can be arbitrarily large and are non-negative.
 */

class BigInteger{
public:
	BigInteger(const string& str) :size(0), mag(nullptr){
		if (str != "0"){
			size = (str.size( )+8) / 9;
			mag = (unsigned int*)calloc(size, sizeof( unsigned int ));
			size_t i = size - 1, j = ( str.size( ) + 8 ) % 9 +1;
			for (auto it = str.begin( ); it != str.end( ); ++it){
				if (!j--){ --i; j = 8; }
				mag[i] = mag[i] * 10 + *it - '0';
			}
		}
	}
	BigInteger(const BigInteger& b) :size(b.size), mag(nullptr){
		if (size){
			mag = (unsigned int*)malloc(size*sizeof( unsigned int ));
			memcpy(mag, b.mag, sizeof(unsigned int)*size);
		}
	}
	BigInteger(BigInteger&& b) :size(b.size), mag(b.mag){
		b.size = 0;
		b.mag = nullptr;
	}
	~BigInteger( ){
		if (mag){
			free(mag);
			mag = nullptr;
		}
	}
	bool operator==( const BigInteger& b )const{
		if (size != b.size)return false;
		if (!size)return true;
		return !memcmp(mag, b.mag, size*sizeof( unsigned int ));
	}
	BigInteger& operator-=( const BigInteger& b )
	{
		unsigned int r = 0, i = 0;
		while (i < b.size){
			if (r + b.mag[i]>mag[i]){ mag[i] += MOD - b.mag[i] - r; r = 1; }
			else{ mag[i] -= b.mag[i] + r; r = 0; }
			++i;
		}
		if (r){
			while (!mag[i])++i;
			--mag[i];
		}
		if (i == size - 1){
			while (!mag[i]) --i;
			size=i+1;
			mag = (unsigned int*)realloc(mag, size*sizeof(unsigned int));
		}
		return *this;
	}
	BigInteger& operator*=( const unsigned int& b ){
		if (!b){size = 0;if (mag){free(mag);mag = nullptr;}}
		else if (b > 1){
			unsigned int r = 0;
			for (size_t i = 0; i < size; ++i){
				unsigned long long t = ( unsigned long long )mag[i] * b + r;
				mag[i] = (unsigned int)(t%MOD);
				r = (unsigned int)(t / MOD);
			}
			if (r){
				mag = (unsigned int*)realloc(mag,++size*sizeof( unsigned int ));
				mag[size - 1] = r;
			}
		}
		return *this;
	}
	BigInteger operator+( const BigInteger& b )const{
		if (!size)return b;
		if (!b.size)return *this;
		unsigned int *nmag = (unsigned int*)malloc(
			( ( size > b.size ? size : b.size ) + 1 )*
			sizeof( unsigned int ));
		size_t nsize = 0;
		unsigned int r = 0;
		while (nsize < size&&nsize < b.size){
			nmag[nsize] = mag[nsize] + b.mag[nsize] + r;
			if (nmag[nsize] >= MOD){ r = 1; nmag[nsize] -= MOD; }
			else r = 0;
			++nsize;
		}
		while (nsize < size){
			nmag[nsize] = mag[nsize] + r;
			if (nmag[nsize] >= MOD){ r = 1; nmag[nsize] -= MOD; }
			else r = 0;
			++nsize;
		}
		while (nsize < b.size){
			nmag[nsize] = b.mag[nsize] + r;
			if (nmag[nsize] >= MOD){ r = 1; nmag[nsize] -= MOD; }
			else r = 0;
			++nsize;
		}
		if (r)
			nmag[nsize++] = 1;
		return BigInteger(nsize, nmag);
	}
	BigInteger operator-( const BigInteger& b )const{
		return BigInteger(*this) -= b;
	}
	BigInteger operator*( const BigInteger& b )const{
		if (!size || !b.size)return BigInteger(0, nullptr);
		if (*this == b&&size > MULTIPLY_SQUARE_THRESHOLD) return square( );
		if (size < KARATSUBA_THRESHOLD || b.size < KARATSUBA_THRESHOLD){
			if (1 == size)return b*mag[0];
			if (1 == b.size)return *this*b.mag[0];
			return multiplyToLen(b);
		}
		else return multiplyKaratsuba(b);
	}
	BigInteger operator*( const unsigned int& b )const{return BigInteger(*this) *= b;}
	string toString( )const{
		if (!size)return "0";
		ostringstream oss;
		oss << mag[size - 1];
		for (size_t i = size-1; i > 0; --i)
			oss<<setw(9)<<setfill('0') << mag[i - 1];
		return oss.str( );
	}
private:
	BigInteger(size_t sz, unsigned int* m) :size(sz), mag(m){}
	BigInteger square( )const{
		if (!size)return *this;
		if (size < KARATSUBA_SQUARE_THRESHOLD)return squareToLen( );
		else return squareKaratsuba( );
	}
	BigInteger squareToLen( )const{
		size_t zlen = size << 1;
		unsigned int* z = (unsigned int*)malloc(zlen*sizeof(unsigned int));
		for (size_t j = 0, i = 0; j < size; ++j){
			unsigned long long product = (unsigned long long)mag[j] * mag[j];
			z[i++] = (unsigned int)(product%MOD);
			z[i++] = (unsigned int)(product / MOD);
		}
		for (size_t i = 0, offset = 1; i < size - 1; ++i, offset += 2)
			addOne(z, size + i, mulAdd(z, mag, offset, size - i - 1, mag[i] << 1));
		if (!z[zlen - 1])--zlen;
		return BigInteger(zlen,z);
	}
	BigInteger squareKaratsuba( )const{
		size_t half = ( size + 1 )>>1;
		BigInteger xl(half, mag);
		BigInteger xh(size - half, mag + half);
		BigInteger xhs = move(xh.square());
		BigInteger xls = move(xl.square());
		return ( xhs.mulNMod(half) + ( xl + xh ).square( ) - ( xhs + xls ) ).mulNMod(half) + xls;
	}
	BigInteger multiplyToLen(const BigInteger& b)const{
		size_t nsz = size + b.size;
		unsigned int* nmag = (unsigned int*)calloc(nsz, sizeof( unsigned int ));
		unsigned long long c,t;
		for (size_t i = 0; i < b.size; ++i){
			c = 0;
			for (size_t j = 0; j < size; ++j){
				t = ( unsigned long long )mag[j] * b.mag[i] + nmag[i + j] + c;
				nmag[i + j] = t%MOD;
				c = t / MOD;
			}
			nmag[i + size] = (unsigned int)c;
		}
		if (!nmag[nsz - 1])--nsz;
		return BigInteger(nsz, nmag);
	}
	BigInteger multiplyKaratsuba(const BigInteger& b)const{
		size_t half = (_max(size,b.size) + 1 ) >> 1;
		BigInteger xl(size<=half?size:half, mag);
		BigInteger yl(b.size <= half ? b.size : half, b.mag);
		size_t xhsz = size > half ? size - half : 0;
		size_t yhsz = b.size > half ? b.size - half : 0;
		BigInteger xh(xhsz, xhsz ? mag + half: nullptr);
		BigInteger yh(yhsz, yhsz ? b.mag + half: nullptr);
		BigInteger p1 = move(xh*yh);
		BigInteger p2 = move(xl*yl);
		return ( p1.mulNMod(half) + (xl+yl)*(xh+yh)-p1-p2).mulNMod(half) + p2;
	}
	static unsigned int mulAdd(unsigned int* out, unsigned int* in, size_t offset, size_t len, unsigned int k){
		unsigned long long kLong = k;
		unsigned long long c = 0;
		for (size_t i = 0; i < len; ++i){
			unsigned long long pro = ( unsigned long long)in[i] * kLong + out[offset] + c;
			out[offset++] = pro%MOD;
			c = pro / MOD;
		}
		return (unsigned int)c;
	}
	static void addOne(unsigned int* out, size_t offset, unsigned int c){
		while ((out[offset] += c )>= MOD){
			c = out[offset] % MOD;
			out[offset++] /= MOD;
		}
	}
	BigInteger& mulNMod(unsigned int n){
		if (size){
			mag = (unsigned int*)realloc(mag, ( size + n )*sizeof( unsigned int ));
			for (size_t i = size + n; i > n; --i)
				mag[i - 1] = mag[i - n - i];
			memset(mag, 0, n*sizeof( unsigned int ));
			size += n;
		}
		return *this;
	}
	template<typename T>
	static T& _max(T& a, T& b){ return a > b ? a : b; }
private:
	unsigned int* mag;
	size_t size;
	static const unsigned long long MOD = 1000000000ULL;
	static const size_t MULTIPLY_SQUARE_THRESHOLD = 20;
	static const size_t KARATSUBA_THRESHOLD = 50;
	static const size_t KARATSUBA_SQUARE_THRESHOLD = 90;
};
class Solution {
public:
    string multiply(string num1, string num2) {
        return (BigInteger(num1)*BigInteger(num2)).toString();
    }
};
