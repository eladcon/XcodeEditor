////////////////////////////////////////////////////////////////////////////////
//
//  JASPER BLUES
//  Copyright 2012 Jasper Blues
//  All Rights Reserved.
//
//  NOTICE: Jasper Blues permits you to use, modify, and distribute this file
//  in accordance with the terms of the license agreement accompanying it.
//
////////////////////////////////////////////////////////////////////////////////


#import <Foundation/Foundation.h>

@class XCProject;
@class XCSourceFile;
@class XCProjectBuildConfig;
@class XCBuildShellScript;
@class XCBuildShellScriptDefinition;

/**
* Represents a target in an xcode project.
*/
@interface XCTarget : NSObject
{

    XCProject* _project;
    NSString* _key;
    NSString* _name;
    NSString* _productName;
    NSString* _productReference;
    NSString* _productType;
    NSString* _defaultConfigurationName;

@private
    NSMutableArray* _members;
    NSMutableArray* _resources;
    NSMutableDictionary* _configurations;
    NSMutableArray *_buildShellScripts;
}

@property(nonatomic, strong, readonly) NSString* key;
@property(nonatomic, strong) NSString* name;
@property(nonatomic, strong) NSString* productName;
@property(nonatomic, strong, readonly) NSString* productReference;
@property(nonatomic, strong, readonly) NSString* productType;

+ (XCTarget*)targetWithProject:(XCProject*)project key:(NSString*)key name:(NSString*)name productName:(NSString*)productName
    productReference:(NSString*)productReference productType:(NSString*)productType;

- (id)initWithProject:(XCProject*)project key:(NSString*)key name:(NSString*)name productName:(NSString*)productName
    productReference:(NSString*)productReference productType:(NSString*)productType;

- (NSArray<XCSourceFile*>*)resources;

- (NSArray<XCSourceFile*>*)members;

- (NSArray<XCBuildShellScript*>*)buildShellScripts;

- (NSDictionary<NSString*,XCProjectBuildConfig*>*)configurations;

- (XCProjectBuildConfig *)configurationWithName:(NSString*)name;

- (XCProjectBuildConfig *)defaultConfiguration;

- (void)addMember:(XCSourceFile*)member;

- (void)makeAndAddShellScript:(XCBuildShellScriptDefinition*)shellScript;

- (void)makeAndAddShellScript:(XCBuildShellScriptDefinition *)shellScript toPosition:(NSUInteger)position;

- (void)removeShellScriptByName:(NSString*)name;

- (void)removeMemberWithKey:(NSString*)key;

- (void)removeMembersWithKeys:(NSArray<NSString*>*)keys;

- (void)removeResourceWithKey:(NSString*)key;

- (void)removeResourcesWithKeys:(NSArray<NSString*>*)keys;

- (void)addDependency:(NSString*)key;

- (instancetype)duplicateWithTargetName:(NSString*)targetName productName:(NSString*)productName;

- (BOOL)isApplicationType;

@end

