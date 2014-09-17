#pragma once
#ifndef OOX_RELS_FILE_INCLUDE_H_
#define OOX_RELS_FILE_INCLUDE_H_

#include "RelationTable.h"
#include "./../FileType.h"
#include "./../FileTypes.h"
#include "./../RId.h"
#include "./../External/External.h"

#include "../../../../Common/DocxFormat/Source/Base/SmartPtr.h"
#include "../../../../Common/DocxFormat/Source/SystemUtility/SystemUtility.h"


namespace PPTX
{
	namespace Rels
	{
		class File
		{
		public:
			File()
			{
			}
			File(const OOX::CPath& filename)
			{
				read(filename);
			}
			~File()
			{
			}

		public:
			void read(const OOX::CPath& filename)
			{
				OOX::CPath strFile = createFileName(filename);

				if (OOX::CSystemUtility::IsFileExist(strFile))
				{
					XmlUtils::CXmlNode oNode;
					if (oNode.FromXmlFile2(strFile.GetPath()))
						Relations = oNode;
				}
			}
			void read2(const OOX::CPath& filename)
			{
				OOX::CPath strFile = filename;

				if (OOX::CSystemUtility::IsFileExist(strFile))
				{
					XmlUtils::CXmlNode oNode;
					if (oNode.FromXmlFile2(strFile.GetPath()))
						Relations = oNode;
				}
			}
			void write(const OOX::CPath& filename) const
			{
				if (0 < Relations.m_items.GetCount())
				{
					OOX::CPath file = createFileName(filename);
					OOX::CSystemUtility::CreateDirectories(file.GetDirectory());

					XmlUtils::CXmlWriter oWriter;
					oWriter.WriteNodeBegin(_T("Relationship"), TRUE);
					oWriter.WriteAttribute(_T("xmlns"), _T("http://schemas.openxmlformats.org/package/2006/relationships"));
					oWriter.WriteNodeEnd(_T("Relationship"), FALSE, TRUE);

					oWriter.WriteString(Relations.toXML());

					oWriter.WriteNodeEnd(_T("Relationship"));

					CDirectory::SaveToFile(file.GetPath(), oWriter.GetXmlString());
				}
			}
			const bool isValid() const
			{
				return true;
			}

		public:
			void registration(const RId& rId, const FileType& type, const OOX::CPath& filename)
			{
				if(!(type == FileTypes::Unknow))
				{
					CString strFileName	= filename.m_strFilename;
					CString strDir		= filename.GetDirectory() + _T("");
					if (_T("") == filename.GetExtention())
					{
						if (type.RelationType() == "http://schemas.openxmlformats.org/officeDocument/2006/relationships/oleObject")
						{
							strFileName += L".bin";
							Relations.registration(rId, type.RelationType(), strDir + strFileName);
						}
						else if (type.RelationType() =="http://schemas.openxmlformats.org/officeDocument/2006/relationships/image")
						{
							strFileName += L".wmf" ;
							Relations.registration(rId, type.RelationType(), strDir + strFileName);
						}
					}
					else
					{
						//Relations.registration(rId, type.RelationType(), replace_extension(filename, L"svm", L"png"));
					}
				}
			}
			void registration(const RId& rId, const smart_ptr<External> external)
			{
				Relations.registration(rId, external);
			}

		private:
			const OOX::CPath createFileName(const OOX::CPath& filename) const
			{
				CString strTemp = filename.GetDirectory() + _T("\\_rels\\");
				if (filename.GetFilename() == _T(""))
					strTemp += _T(".rels");
				else
					strTemp += (filename.GetFilename() + _T(".rels"));
				return strTemp;
			}
			
		public:
			RelationTable Relations;
		};
	} // namespace Rels
} // namespace PPTX

#endif // OOX_RELS_FILE_INCLUDE_H_