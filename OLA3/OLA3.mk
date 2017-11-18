##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=OLA3
ConfigurationName      :=Debug
WorkspacePath          :=/Users/biyeuphuong/Documents/Tien
ProjectPath            :=/Users/biyeuphuong/Documents/Tien/OLA3
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
ObjectsFileList        :="OLA3.txt"
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
Objects0=$(IntermediateDirectory)/Movie.cpp$(ObjectSuffix) $(IntermediateDirectory)/ola3.cpp$(ObjectSuffix) $(IntermediateDirectory)/StoreItem.cpp$(ObjectSuffix) $(IntermediateDirectory)/Book.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/Movie.cpp$(ObjectSuffix): Movie.cpp $(IntermediateDirectory)/Movie.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/biyeuphuong/Documents/Tien/OLA3/Movie.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Movie.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Movie.cpp$(DependSuffix): Movie.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Movie.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Movie.cpp$(DependSuffix) -MM Movie.cpp

$(IntermediateDirectory)/Movie.cpp$(PreprocessSuffix): Movie.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Movie.cpp$(PreprocessSuffix) Movie.cpp

$(IntermediateDirectory)/ola3.cpp$(ObjectSuffix): ola3.cpp $(IntermediateDirectory)/ola3.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/biyeuphuong/Documents/Tien/OLA3/ola3.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ola3.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ola3.cpp$(DependSuffix): ola3.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ola3.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ola3.cpp$(DependSuffix) -MM ola3.cpp

$(IntermediateDirectory)/ola3.cpp$(PreprocessSuffix): ola3.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ola3.cpp$(PreprocessSuffix) ola3.cpp

$(IntermediateDirectory)/StoreItem.cpp$(ObjectSuffix): StoreItem.cpp $(IntermediateDirectory)/StoreItem.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/biyeuphuong/Documents/Tien/OLA3/StoreItem.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/StoreItem.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/StoreItem.cpp$(DependSuffix): StoreItem.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/StoreItem.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/StoreItem.cpp$(DependSuffix) -MM StoreItem.cpp

$(IntermediateDirectory)/StoreItem.cpp$(PreprocessSuffix): StoreItem.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/StoreItem.cpp$(PreprocessSuffix) StoreItem.cpp

$(IntermediateDirectory)/Book.cpp$(ObjectSuffix): Book.cpp $(IntermediateDirectory)/Book.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/biyeuphuong/Documents/Tien/OLA3/Book.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Book.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Book.cpp$(DependSuffix): Book.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Book.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Book.cpp$(DependSuffix) -MM Book.cpp

$(IntermediateDirectory)/Book.cpp$(PreprocessSuffix): Book.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Book.cpp$(PreprocessSuffix) Book.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


