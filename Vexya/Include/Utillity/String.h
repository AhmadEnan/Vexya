#pragma once

#include "typedefs.h"

#include <string> // Just that we support the STL's strings
#include <vector> // will be changed when we has a custom Vector class

namespace Vexya 
{
	struct String
	{
	private: // Private Members
		// The actual string buffer
		char* m_Buffer;

		// The length of the string (execluding the null terminating character)
		size_t m_Length;

	public: // Constructors and Destructor

		// Default constructor
		// Buffer = '\0'
		// Length = 0
		String();

		// Char constructor
		// Buffer = 'c\0'
		// Length = 1
		String(const char& c);

		// Char pointer constructor
		// Buffer = 'string\0'
		// Length = length of 'string'
		String(const char* string);

		// STL's string constructor
		// Buffer = string.c_str()
		// Length = length of 'string'
		String(const std::string& string);

		// Copy constructor
		// Buffer = string.GetBuffer();
		// Length = string.GetLength();
		String(const String& string);

		// Destructor
		// Free the buffer
		~String();

	public: // Operators
		String& operator=(const char& c);
		String& operator=(const char* s);
		String& operator=(const std::string& s);
		String& operator=(const String& s);

		friend String operator+(const String& LHS, const char& RHS);
		friend String operator+(const String& LHS, const char* RHS);
		friend String operator+(const String& LHS, const std::string& RHS);
		friend String operator+(const String& LHS, const String& RHS);

		String& operator+=(const char& RHS);
		String& operator+=(const char* RHS);
		String& operator+=(const std::string& RHS);
		String& operator+=(const String& RHS);

		friend bool operator ==(const String& LHS, const char& RHS);
		friend bool operator ==(const String& LHS, const char* RHS);
		friend bool operator ==(const String& LHS, const std::string& RHS);
		friend bool operator ==(const String& LHS, const String& RHS);

		friend bool operator !=(const String& LHS, const char& RHS);
		friend bool operator !=(const String& LHS, const char* RHS);
		friend bool operator !=(const String& LHS, const std::string& RHS);
		friend bool operator !=(const String& LHS, const String& RHS);

		char& operator[] (size_t j) const;

	public: // STL Stream Support
		friend std::ostream& operator<< (std::ostream&, const String&);  // cout << String 
		friend std::istream& operator>> (std::istream&, String&);       // cin >> String

	public: // Fancy String Utillities
		static std::vector<String> SplitToWords(String& string, const char& delimiter = ' ');

		// checks if 'substr' is a substring of 'str' and returns the index of 'substr' in 'str'
		static size_t GetSubString(const String& substr, const String& str);
		static bool IsSubString(const String& substr, const String& str);

		static String SubString(const String& s, const size_t& from, const size_t& to);

		static String GetBetween(const String& source, const String& from, const String& to);

		// replaces each 'c1' with 'c2'
		static void ReplaceEach(String& str, const char& c1, const char& c2);

		// replaces each 's1' with 's2'
		static void ReplaceEach(String& str, String& s1, String& s2);

		// Counts the number of 'token' in a string
		static size_t CountOf(const String& str, const String& token);

	public: // Getters
		char* GetBuffer() const { return m_Buffer; }
		const size_t GetLength() const { return m_Length; }
		char& Get(size_t index) const { return m_Buffer[index]; }
		std::string GetSTDString() const { return std::string(m_Buffer); }
	};

}