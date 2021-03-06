// © Opaque Multimedia 2014

using UnrealBuildTool;
using System.Collections.Generic;

public class K4UIntroductionTarget : TargetRules
{
	public K4UIntroductionTarget(TargetInfo Target)
	{
		Type = TargetType.Game;
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
