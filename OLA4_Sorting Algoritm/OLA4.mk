##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=OLA4
ConfigurationName      :=Debug
WorkspacePath          :=/Users/biyeuphuong/Documents/Tien
ProjectPath            :=/Users/biyeuphuong/Documents/Tien/OLA4
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
ObjectsFileList        :="OLA4.txt"
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
Objects0=$(IntermediateDirectory)/Algorithm.cpp$(ObjectSuffix) $(IntermediateDirectory)/ola4.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/Algorithm.cpp$(ObjectSuffix): Algorithm.cpp $(IntermediateDirectory)/Algorithm.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/biyeuphuong/Documents/Tien/OLA4/Algorithm.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Algorithm.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Algorithm.cpp$(DependSuffix): Algorithm.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Algorithm.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Algorithm.cpp$(DependSuffix) -MM Algorithm.cpp

$(IntermediateDirectory)/Algorithm.cpp$(PreprocessSuffix): Algorithm.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Algorithm.cpp$(PreprocessSuffix) Algorithm.cpp

$(IntermediateDirectory)/ola4.cpp$(ObjectSuffix): ola4.cpp $(IntermediateDirectory)/ola4.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/biyeuphuong/Documents/Tien/OLA4/ola4.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ola4.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ola4.cpp$(DependSuffix): ola4.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ola4.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ola4.cpp$(DependSuffix) -MM ola4.cpp

$(IntermediateDirectory)/ola4.cpp$(PreprocessSuffix): ola4.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ola4.cpp$(PreprocessSuffix) ola4.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


