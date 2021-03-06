//////////////////////////////////////////////////////////////////////////
//
// ZPatcher - Patcher system - Part of the ZUpdater suite
// Felipe "Zoc" Silveira - (c) 2016
//
//////////////////////////////////////////////////////////////////////////
//
// ZPatcherCurrentVersion.h
// This file holds the current version of the patch file being created and
// the supported Patch Operations
//
//////////////////////////////////////////////////////////////////////////

#ifndef _ZPATCHERCURRENTVERSION_H_
#define _ZPATCHERCURRENTVERSION_H_

namespace ZPatcher
{
	static const unsigned char ZPatcher_Version = 1;

	enum PatchOperation
	{
		Patch_File_Delete		= 1,	// Delete an existing file (Removed on the new version)
		Patch_File_Add			= 2,	// Add a file contained in the patch
		Patch_File_Replace		= 3,	// Replace a file with the one contained in the patch
		Patch_Dir_Add			= 4,	// Add a Directory that is new in the new version
		Patch_MAX				= Patch_Dir_Add,
	};
}


#endif // _ZPATCHERCURRENTVERSION_H_
