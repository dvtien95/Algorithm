##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Bai1
ConfigurationName      :=Debug
WorkspacePath          :=/Users/biyeuphuong/Documents/Tien
ProjectPath            :=/Users/biyeuphuong/Documents/Tien/Bai1
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
ObjectsFileList        :="Bai1.txt"
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
Objects0=$(IntermediateDirectory)/Student.cpp$(ObjectSuffix) $(IntermediateDirectory)/Roster.cpp$(ObjectSuffix) $(IntermediateDirectory)/ola1.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/Student.cpp$(ObjectSuffix): Student.cpp $(IntermediateDirectory)/Student.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/biyeuphuong/Documents/Tien/Bai1/Student.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Student.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Student.cpp$(DependSuffix): Student.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Student.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Student.cpp$(DependSuffix) -MM Student.cpp

$(IntermediateDirectory)/Student.cpp$(PreprocessSuffix): Student.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Student.cpp$(PreprocessSuffix) Student.cpp

$(IntermediateDirectory)/Roster.cpp$(ObjectSuffix): Roster.cpp $(IntermediateDirectory)/Roster.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/biyeuphuong/Documents/Tien/Bai1/Roster.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Roster.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Roster.cpp$(DependSuffix): Roster.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Roster.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Roster.cpp$(DependSuffix) -MM Roster.cpp

$(IntermediateDirectory)/Roster.cpp$(PreprocessSuffix): Roster.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Roster.cpp$(PreprocessSuffix) Roster.cpp

$(IntermediateDirectory)/ola1.cpp$(ObjectSuffix): ola1.cpp $(IntermediateDirectory)/ola1.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/biyeuphuong/Documents/Tien/Bai1/ola1.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ola1.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ola1.cpp$(DependSuffix): ola1.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ola1.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ola1.cpp$(DependSuffix) -MM ola1.cpp

$(IntermediateDirectory)/ola1.cpp$(PreprocessSuffix): ola1.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ola1.cpp$(PreprocessSuffix) ola1.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


