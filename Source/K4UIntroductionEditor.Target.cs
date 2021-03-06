// © Opaque Multimedia 2014

using UnrealBuildTool;
using System.Collections.Generic;

public class K4UIntroductionEditorTarget : TargetRules
{
	public K4UIntroductionEditorTarget(TargetInfo Target)
	{
		Type = TargetType.Editor;
	}

	//
	// TargetRules interface.
	//

	public override void SetupBinaries(
		TargetInfo Target,
		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
		ref List<string> OutExtraModuleNames
		)
	{
		OutExtraModuleNames.AddRange( new string[] { "K4UIntroduction" } );
	}
}
