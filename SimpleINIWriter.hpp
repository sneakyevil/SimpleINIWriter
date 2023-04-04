#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>

class CINIWriterKey
{
public:
	std::string Value;

	template <typename T>
	void operator=(T m_Value) { Value = std::to_string(m_Value); }
	void operator=(std::string m_String) { Value = "\"" + m_String + "\""; }
	void operator=(const char* m_String) { operator=(std::string(m_String)); }
};

class CINIWriterSection
{
public:
	std::map<std::string, CINIWriterKey> Keys;

	CINIWriterKey& operator[](const char* m_Key) { return Keys[m_Key]; }
};

class CINIWriter
{
public:
	std::map<std::string, CINIWriterSection> Sections;

	CINIWriterSection& operator[](const char* m_Key) { return Sections[m_Key]; }

	operator std::string()
	{
		std::string m_String;

		for (std::pair<std::string, CINIWriterSection> m_Section : Sections)
		{
			if (!m_String.empty())
				m_String += "\n\n";

			m_String += "[" + m_Section.first + "]";

			for (std::pair<std::string, CINIWriterKey> m_Key : m_Section.second.Keys)
				m_String += "\n" + m_Key.first + "=" + m_Key.second.Value;
		}
		
		return m_String;
	}

	std::string GetString() { return operator std::string(); }

	bool OutputFile(const char* m_Path)
	{
		FILE* m_File = fopen(m_Path, "w");
		if (!m_File)
			return false;

		std::string m_String = GetString();
		fwrite(&m_String[0], sizeof(char), m_String.size(), m_File);
		fclose(m_File);

		return true;
	}
};