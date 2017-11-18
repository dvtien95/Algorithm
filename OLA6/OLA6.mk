##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=OLA6
ConfigurationName      :=Debug
WorkspacePath          :=/Users/biyeuphuong/Documents/Tien
ProjectPath            :=/Users/biyeuphuong/Documents/Tien/OLA6
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Tien Dinh Vinh
Date                   :=02/07/2017
CodeLitePath           :="/Users/biyeuphuong/Library/Application Support/codelite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="OLA6.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/private/var/folders/xr/jpjgjhv50_94y8bjr4hbthg80000gn/T/AppTranslocation/92A68777-5CAB-42CD-B8E2-607F7CBFC972/d/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/ola6.cpp$(ObjectSuffix) $(IntermediateDirectory)/WordChecker.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/ola6.cpp$(ObjectSuffix): ola6.cpp $(IntermediateDirectory)/ola6.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/biyeuphuong/Documents/Tien/OLA6/ola6.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ola6.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ola6.cpp$(DependSuffix): ola6.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ola6.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ola6.cpp$(DependSuffix) -MM ola6.cpp

$(IntermediateDirectory)/ola6.cpp$(PreprocessSuffix): ola6.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ola6.cpp$(PreprocessSuffix) ola6.cpp

$(IntermediateDirectory)/WordChecker.cpp$(ObjectSuffix): WordChecker.cpp $(IntermediateDirectory)/WordChecker.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/biyeuphuong/Documents/Tien/OLA6/WordChecker.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/WordChecker.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/WordChecker.cpp$(DependSuffix): WordChecker.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/WordChecker.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/WordChecker.cpp$(DependSuffix) -MM WordChecker.cpp

$(IntermediateDirectory)/WordChecker.cpp$(PreprocessSuffix): WordChecker.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/WordChecker.cpp$(PreprocessSuffix) WordChecker.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


