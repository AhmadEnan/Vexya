#include <Utillity/String.h>
#include <iostream>

namespace Vexya
{
	// Default Constructor
	String::String()
	{
		m_Buffer = reinterpret_cast<char*>(malloc(sizeof(char)));
		*m_Buffer = '\0';
		m_Length = 0;
	}

	// Char Constructor
	String::String(const char& c)
	{
		m_Buffer = reinterpret_cast<char*>(malloc(sizeof(char) * 2));
		m_Buffer[0] = c;
		m_Buffer[1] = '\0';
		m_Length = 1;
	}

	// Char Pointer Constructor
	String::String(const char* string)
	{
		const size_t len = strlen(string) + 1;
		m_Buffer = reinterpret_cast<char*>(malloc(len));
		memset(m_Buffer, 0, len);
		memcpy(m_Buffer, string, len - 1);
		m_Length = len - 1;
	}

	// STL's String Constructor
	String::String(const std::string& string)
	{
		const size_t len = strlen(string.c_str()) + 1;
		m_Buffer = reinterpret_cast<char*>(malloc(len));
		memset(m_Buffer, 0, len);
		memcpy(m_Buffer, string.c_str(), len - 1);
		m_Length = len - 1;
	}

	// Copy Constructor
	String::String(const String& string)
	{
		size_t buffSize = string.m_Length + 1;
		m_Buffer = reinterpret_cast<char*>(malloc(buffSize));
		memset(m_Buffer, 0, buffSize);
		memcpy(m_Buffer, string.m_Buffer, buffSize);
		m_Length = string.m_Length;
	}

	// Destructor
	String::~String()
	{
		free(m_Buffer);
		m_Buffer = nullptr;
		m_Length = 0;
	}

	// Operators
	String& String::operator= (const char& c)
	{
		if (m_Length == 1 && m_Buffer[0] == c) return *this;

		free(m_Buffer);
		m_Buffer = reinterpret_cast<char*>(malloc(sizeof(char) * 2));
		m_Buffer[0] = c;
		m_Buffer[1] = '\0';
		m_Length = 1;
		return *this;
	}

	String& String::operator= (const char* s)
	{
		if (s == m_Buffer) return *this;

		free(m_Buffer);
		const size_t len = strlen(s) + 1;
		m_Buffer = reinterpret_cast<char*>(malloc(len));
		memset(m_Buffer, 0, len);
		memcpy(m_Buffer, s, len - 1);
		m_Length = len - 1;
		return *this;
	}

	String& String::operator= (const std::string& s)
	{
		if (strlen(s.c_str()) == m_Length || m_Buffer == s.c_str()) return *this;

		free(m_Buffer);
		const size_t len = strlen(s.c_str()) + 1;
		m_Buffer = reinterpret_cast<char*>(malloc(len));
		memset(m_Buffer, 0, len);
		memcpy(m_Buffer, s.c_str(), len - 1);
		m_Length = len - 1;
		return *this;
	}

	String& String::operator= (const String& s)
	{
		if (s == *this) return *this;

		free(m_Buffer);
		size_t buffSize = s.m_Length + 1;
		m_Buffer = reinterpret_cast<char*>(malloc(buffSize));
		memset(m_Buffer, 0, buffSize);
		memcpy(m_Buffer, s.m_Buffer, buffSize);
		m_Length = s.m_Length;
		return *this;
	}

	String operator+(const String& LHS, const char& RHS)
	{
		String result;
		const size_t newSize = LHS.m_Length + 2;
		char* temp = reinterpret_cast<char*>(malloc(newSize));
		memset(temp, 0, newSize);
		memcpy(temp, LHS.m_Buffer, newSize);
		free(result.m_Buffer);
		temp[newSize - 2] = RHS;
		temp[newSize - 1] = '\0';
		result.m_Buffer = temp;
		result.m_Length = newSize - 1;
		return String(result);
	}

	String operator+(const String& LHS, const char* RHS)
	{
		String result;
		const size_t RHSLen = strlen(RHS);
		const size_t newSize = LHS.m_Length + RHSLen + 1;
		char* temp = reinterpret_cast<char*>(malloc(newSize));
		memset(temp, 0, newSize);
		memcpy(temp, LHS.m_Buffer, RHSLen);
		free(result.m_Buffer);

		for (int i = 0; i < RHSLen; i++) // Can Be Optimized
		{
			temp[LHS.m_Length + i] = RHS[i];
		}

		temp[newSize - 1] = '\0';
		result.m_Buffer = temp;
		result.m_Length = newSize - 1;
		return String(result);
	}

	String operator+(const String& LHS, const std::string& RHS)
	{
		return LHS + RHS.c_str();
	}

	String operator+(const String& LHS, const String& RHS)
	{
		return LHS + RHS.m_Buffer;
	}


	String& String::operator+=(const char& RHS)
	{
		const size_t newSize = m_Length + 2;
		char* temp = reinterpret_cast<char*>(malloc(newSize));
		memset(temp, 0, newSize);
		memcpy(temp, m_Buffer, newSize - 1);
		free(m_Buffer); m_Buffer = nullptr;
		temp[newSize - 2] = RHS;
		temp[newSize - 1] = '\0';
		m_Buffer = temp;
		m_Length++;
		return *this;
	}

	String& String::operator+=(const char* RHS)
	{
		const size_t RHSLen = strlen(RHS);
		const size_t newSize = m_Length + RHSLen + 1;
		char* temp = reinterpret_cast<char*>(malloc(newSize));
		memset(temp, 0, newSize);
		memcpy(temp, m_Buffer, RHSLen);
		free(m_Buffer); m_Buffer = nullptr;

		for (int i = 0; i < RHSLen; i++) // Can Be Optimized
		{
			temp[m_Length + i] = RHS[i];
		}

		temp[newSize - 1] = '\0';
		m_Buffer = temp;
		m_Length = newSize - 1;
		return *this;
	}

	String& String::operator+=(const std::string& RHS)
	{
		*this += RHS.c_str();
		return *this;
	}

	String& String::operator+=(const String& RHS)
	{
		*this += RHS.m_Buffer;
		return *this;
	}

	bool operator ==(const String& LHS, const char& RHS)
	{
		if (LHS.m_Length != 1) return false;
		return LHS.m_Buffer[0] == RHS;
	}

	bool operator ==(const String& LHS, const char* RHS)
	{
		if (strlen(RHS) != LHS.m_Length) return false;

		for (int i = 0; i < LHS.m_Length - 1; i++)
		{
			if (RHS[i] != LHS[i]) return false;
		}

		return true;
	}

	bool operator ==(const String& LHS, const std::string& RHS)
	{
		if (strlen(RHS.c_str()) != LHS.m_Length) return false;

		for (int i = 0; i < LHS.m_Length - 1; i++)
		{
			if (RHS[i] != LHS[i]) return false;
		}

		return true;
	}

	bool operator ==(const String& LHS, const String& RHS)
	{
		if (LHS.m_Length != RHS.m_Length) return false;

		for (int i = 0; i < LHS.m_Length - 1; i++)
		{
			if (RHS[i] != LHS[i]) return false;
		}

		return true;
	}

	bool operator !=(const String& LHS, const char& RHS)
	{
		if (LHS.m_Length != 1) return true;
		return !(LHS == RHS);
	}

	bool operator !=(const String& LHS, const char* RHS)
	{
		if (LHS.m_Length != strlen(RHS)) return true;
		return !(LHS == RHS);
	}

	bool operator !=(const String& LHS, const std::string& RHS)
	{
		if (LHS.m_Length != strlen(RHS.c_str())) return true;
		return !(LHS == RHS);
	}

	bool operator !=(const String& LHS, const String& RHS)
	{
		if (LHS.m_Length != RHS.m_Length) return true;
		return !(LHS == RHS);
	}

	char& String::operator[] (size_t j) const
	{
		// AT_ENGINE_FATAL("Index out of range!");
		return m_Buffer[j];
	};

	std::vector<String> String::SplitToWords(String& string, const char& delimiter)
	{
		String temp = string;
		String word = "";
		size_t num = NULL;

		temp += delimiter;

		const size_t len = temp.GetLength();
		std::vector<String> result;

		for (int i = 0; i < len; i++)
		{
			if (temp[i] != delimiter)
				word = word + temp[i];

			else
			{
				if ((int)word.GetLength() != 0)
					result.push_back(word);

				word = "";
			}
		}

		// return the splitted strings 
		return result;
	}

	size_t String::GetSubString(const String& substr, const String& str)
	{
		size_t M = substr.GetLength();
		size_t N = str.GetLength();

		/* A loop to slide pat[] one by one */
		for (int i = 0; i <= N - M; i++)
		{
			int j;

			/* For current index i, check for pattern match */
			for (j = 0; j < M; j++)
				if (str[i + j] != substr[j])
					break;

			if (j == M)
				return i;
		}

		return -1;
	}

	bool String::IsSubString(const String& substr, const String& str)
	{
		return GetSubString(substr, str);
	}

	String String::SubString(const String& s, const size_t& from, const size_t& to)
	{
		const size_t len = to - from + 2;
		char* temp = reinterpret_cast<char*>(malloc(len));
		memset(temp, 0, len);
		memcpy(temp, &s[from], len - 1);
		String result(temp);
		return result;
	}

	String String::GetBetween(const String& source, const String& from, const String& to)
	{

		const size_t pos1 = GetSubString(from, source) + from.GetLength();
		const size_t pos2 = GetSubString(to, source) - 1;
		const String result = SubString(source, pos1, pos2);
		return result;
	}

	void String::ReplaceEach(String& str, const char& c1, const char& c2)
	{
		for (int i = 0; i < str.GetLength() - 1; i++)
		{
			if (str[i] == c1) str[i] = c2;
		}
	}

	void String::ReplaceEach(String& str, String& s1, String& s2)
	{
		std::vector words = SplitToWords(str);
		String result;
		for (auto w : words)
		{
			if (w == s1) w = s2;
			result += w;
		}

		str = result;
	}

	size_t String::CountOf(const String& str, const String& token)
	{
		size_t M = token.GetLength();
		size_t N = str.GetLength();
		int res = 0;

		/* A loop to slide pat[] one by one */
		for (int i = 0; i <= N - M; i++)
		{
			/* For current index i, check for
			   pattern match */
			int j;
			for (j = 0; j < M; j++)
				if (str[i + j] != token[j])
					break;

			// if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
			if (j == M)
			{
				res++;
				j = 0;
			}
		}
		return res;
	}

	std::ostream& operator<< (std::ostream& os, const String& s)
	{
		const size_t len = s.GetLength();
		if (len > 0) os << s.m_Buffer;
		else os << "";

		return os;
	}

	std::istream& operator>> (std::istream& is, String& s)
	{
		// Maximum Allowed Input Characters is '1024'
		char* c = reinterpret_cast<char*>(malloc(1024)); // Waste of Memory (but gets free ASAP, so don't care)
		is >> c;
		s = String(c);
		free(c);

		return is;
	}

}