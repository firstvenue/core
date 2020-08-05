#include "CBookItem.h"

CBookItem::CBookItem()
{

}

CBookItem::~CBookItem()
{

}

bool CBookItem::ReadItem(XmlUtils::CXmlLiteReader &oXmlLiteReader, int depth)
{
    if (!oXmlLiteReader.IsValid() || oXmlLiteReader.IsEmptyNode())
        return false;

    if (oXmlLiteReader.ReadNextSiblingNode(depth))
    {
        if (oXmlLiteReader.GetAttributesCount() > 0 &&
            oXmlLiteReader.MoveToFirstAttribute())
        {
            std::wstring sAttributeName = oXmlLiteReader.GetName();
            while (!sAttributeName.empty())
            {
                std::wstring sAttributeValue = oXmlLiteReader.GetText();
                if (sAttributeName == L"href")
                {
                    if (sAttributeValue.find(L"/") == std::wstring::npos)
                        m_sRef = sAttributeValue;
                    else
                        m_sRef = sAttributeValue.substr(sAttributeValue.find_last_of(L"/") + 1, sAttributeValue.length());
                }
                else if (sAttributeName == L"id")
                    m_sID = sAttributeValue;
                else if (sAttributeName == L"media-type")
                {
                    if (sAttributeValue == L"image/jpeg")
                        m_eType = ItemType::image;
                    else if (sAttributeValue == L"application/xhtml+xml")
                        m_eType = ItemType::xhtml;
                    else if (sAttributeValue == L"text/css")
                        m_eType = ItemType::css;
                    else if (sAttributeValue == L"application/x-dtbncx+xml")
                        m_eType = ItemType::toc;
                    else if (sAttributeValue == L"application/x-font-ttf")
                        m_eType = ItemType::font;
                }

                if (!oXmlLiteReader.MoveToNextAttribute())
                    break;

                sAttributeName = oXmlLiteReader.GetName();
            }
        }
        else
            return false;
    }
    else
        return false;
    return true;
}

std::wstring CBookItem::GetID()
{
    return m_sID;
}

std::wstring CBookItem::GetRef()
{
    return m_sRef;
}
