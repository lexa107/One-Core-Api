/*
 *    Virtual Admin Tools Folder
 *
 *    Copyright 2008                Johannes Anderwald
 *    Copyright 2009                Andrew Hill
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _SHFLDR_ADMINTOOLS_H_
#define _SHFLDR_ADMINTOOLS_H_

class CAdminToolsFolder :
    public CComCoClass<CAdminToolsFolder, &CLSID_AdminFolderShortcut>,
    public CComObjectRootEx<CComMultiThreadModelNoCS>,
    public IShellFolder2,
    public IPersistFolder2
{
    private:
        CLSID *pclsid;

        LPITEMIDLIST pidlRoot;  /* absolute pidl */
        LPWSTR szTarget;

        int dwAttributes;        /* attributes returned by GetAttributesOf FIXME: use it */
    public:
        CAdminToolsFolder();
        ~CAdminToolsFolder();
        HRESULT WINAPI FinalConstruct();

        // IShellFolder
        virtual HRESULT WINAPI ParseDisplayName (HWND hwndOwner, LPBC pbc, LPOLESTR lpszDisplayName, DWORD *pchEaten, LPITEMIDLIST *ppidl, DWORD *pdwAttributes);
        virtual HRESULT WINAPI EnumObjects(HWND hwndOwner, DWORD dwFlags, LPENUMIDLIST *ppEnumIDList);
        virtual HRESULT WINAPI BindToObject(LPCITEMIDLIST pidl, LPBC pbcReserved, REFIID riid, LPVOID *ppvOut);
        virtual HRESULT WINAPI BindToStorage(LPCITEMIDLIST pidl, LPBC pbcReserved, REFIID riid, LPVOID *ppvOut);
        virtual HRESULT WINAPI CompareIDs(LPARAM lParam, LPCITEMIDLIST pidl1, LPCITEMIDLIST pidl2);
        virtual HRESULT WINAPI CreateViewObject(HWND hwndOwner, REFIID riid, LPVOID *ppvOut);
        virtual HRESULT WINAPI GetAttributesOf (UINT cidl, LPCITEMIDLIST *apidl, DWORD *rgfInOut);
        virtual HRESULT WINAPI GetUIObjectOf(HWND hwndOwner, UINT cidl, LPCITEMIDLIST *apidl, REFIID riid, UINT * prgfInOut, LPVOID * ppvOut);
        virtual HRESULT WINAPI GetDisplayNameOf(LPCITEMIDLIST pidl, DWORD dwFlags, LPSTRRET strRet);
        virtual HRESULT WINAPI SetNameOf(HWND hwndOwner, LPCITEMIDLIST pidl, LPCOLESTR lpName, DWORD dwFlags, LPITEMIDLIST *pPidlOut);

        /* ShellFolder2 */
        virtual HRESULT WINAPI GetDefaultSearchGUID(GUID *pguid);
        virtual HRESULT WINAPI EnumSearches(IEnumExtraSearch **ppenum);
        virtual HRESULT WINAPI GetDefaultColumn(DWORD dwRes, ULONG *pSort, ULONG *pDisplay);
        virtual HRESULT WINAPI GetDefaultColumnState(UINT iColumn, DWORD *pcsFlags);
        virtual HRESULT WINAPI GetDetailsEx(LPCITEMIDLIST pidl, const SHCOLUMNID *pscid, VARIANT *pv);
        virtual HRESULT WINAPI GetDetailsOf(LPCITEMIDLIST pidl, UINT iColumn, SHELLDETAILS *psd);
        virtual HRESULT WINAPI MapColumnToSCID(UINT column, SHCOLUMNID *pscid);

        // IPersist
        virtual HRESULT WINAPI GetClassID(CLSID *lpClassId);

        // IPersistFolder
        virtual HRESULT WINAPI Initialize(LPCITEMIDLIST pidl);

        // IPersistFolder2
        virtual HRESULT WINAPI GetCurFolder(LPITEMIDLIST * pidl);

        DECLARE_REGISTRY_RESOURCEID(IDR_ADMINFOLDERSHORTCUT)
        DECLARE_NOT_AGGREGATABLE(CAdminToolsFolder)

        DECLARE_PROTECT_FINAL_CONSTRUCT()

        BEGIN_COM_MAP(CAdminToolsFolder)
        COM_INTERFACE_ENTRY_IID(IID_IShellFolder2, IShellFolder2)
        COM_INTERFACE_ENTRY_IID(IID_IShellFolder, IShellFolder)
        COM_INTERFACE_ENTRY_IID(IID_IPersistFolder, IPersistFolder)
        COM_INTERFACE_ENTRY_IID(IID_IPersistFolder2, IPersistFolder2)
        COM_INTERFACE_ENTRY_IID(IID_IPersist, IPersist)
        END_COM_MAP()
};

#endif /* _SHFLDR_ADMINTOOLS_H_ */
