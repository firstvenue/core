#pragma once
#ifndef OOX_MEDIA_INCLUDE_H_
#define OOX_MEDIA_INCLUDE_H_

#include "..\File.h"
#include "..\FileTypes.h"

#ifdef AVS_OFFICE_SVM_FILE
#include "OfficeSvmFile.h"
#include "SvmConverter.h"
#endif


namespace PPTX
{
	class Media : public File
	{
	public:
		Media()
		{
		}
		Media(const OOX::CPath& filename)
		{
			read(filename);
		}
		virtual ~Media()
		{
		}

	public:
		virtual void read(const OOX::CPath& filename)
		{
			m_filename = filename;
		}
		virtual void write(const OOX::CPath& filename, const OOX::CPath& directory, ContentTypes::File& content) const
		{
			//std::wstring newFilename = filename.filename();
			//boost::filesystem::wpath newFilePath = filename.parent_path();
			//boost::replace_all(newFilename, L" ", L"_");
			//if (boost::filesystem::exists(m_filename) && !boost::filesystem::exists(newFilePath/newFilename))	
			//{
			//	if (m_filename.extension() == L".svm")
			//		ConvertSvmToImage(m_filename, replace_extension(newFilePath/newFilename, L"png"));
			//	else
			//		boost::filesystem::copy_file(m_filename, newFilePath/newFilename);
			//}
			//if (m_filename.extension() == L".svm")
			//	content.Default->add(replace_extension(newFilePath/newFilename, L"png"));
			//else
			//	content.Default->add(m_filename);
		}

	public:
		const OOX::CPath filename() const
		{
			return m_filename;
		}
		void copy_to(const OOX::CPath& path) const
		{
			//std::wstring newFilename = m_filename.filename();
			//boost::replace_all(newFilename, L" ", L"_");

			//if (boost::filesystem::exists(m_filename) && !boost::filesystem::exists(path/m_filename.filename()))
			//	boost::filesystem::copy_file(m_filename, path/newFilename);
		}

	protected:
		OOX::CPath	m_filename;
	};
} // namespace PPTX

#endif // OOX_MEDIA_INCLUDE_H_