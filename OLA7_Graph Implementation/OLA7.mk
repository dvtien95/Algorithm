##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=OLA7
ConfigurationName      :=Debug
WorkspacePath          :=/Users/biyeuphuong/Documents/Tien
ProjectPath            :=/Users/biyeuphuong/Documents/Tien/OLA7
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
ObjectsFileList        :="OLA7.txt"
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
Objects0=$(IntermediateDirectory)/ola7.cpp$(ObjectSuffix) $(IntermediateDirectory)/Graph.cpp$(ObjectSuffix) $(IntermediateDirectory)/Menu.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/ola7.cpp$(ObjectSuffix): ola7.cpp $(IntermediateDirectory)/ola7.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/biyeuphuong/Documents/Tien/OLA7/ola7.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ola7.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ola7.cpp$(DependSuffix): ola7.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ola7.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ola7.cpp$(DependSuffix) -MM ola7.cpp

$(IntermediateDirectory)/ola7.cpp$(PreprocessSuffix): ola7.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ola7.cpp$(PreprocessSuffix) ola7.cpp

$(IntermediateDirectory)/Graph.cpp$(ObjectSuffix): Graph.cpp $(IntermediateDirectory)/Graph.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/biyeuphuong/Documents/Tien/OLA7/Graph.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Graph.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Graph.cpp$(DependSuffix): Graph.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Graph.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Graph.cpp$(DependSuffix) -MM Graph.cpp

$(IntermediateDirectory)/Graph.cpp$(PreprocessSuffix): Graph.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Graph.cpp$(PreprocessSuffix) Graph.cpp

$(IntermediateDirectory)/Menu.cpp$(ObjectSuffix): Menu.cpp $(IntermediateDirectory)/Menu.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/biyeuphuong/Documents/Tien/OLA7/Menu.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Menu.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Menu.cpp$(DependSuffix): Menu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Menu.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Menu.cpp$(DependSuffix) -MM Menu.cpp

$(IntermediateDirectory)/Menu.cpp$(PreprocessSuffix): Menu.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Menu.cpp$(PreprocessSuffix) Menu.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


