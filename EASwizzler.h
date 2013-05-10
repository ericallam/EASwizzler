#import <Foundation/Foundation.h>

@interface EASwizzler : NSObject

// Allows you to swizzle a class method
+(void)swizzleClass:(id)cls
 replaceClassMethod:(SEL)origMethodSelector
         withMethod:(SEL)replacementMethodSelector;

// Swizzle an instance method
+(void)swizzleClass:(id)cls
      replaceMethod:(SEL)origMethodSelector
         withMethod:(SEL)replacementMethodSelector;

// Swizzle an instance method on a class that belongs to a Class Cluster
+(void)swizzleClassOfInstance:(id)inst
                replaceMethod:(SEL)origMethodSelector
                   withMethod:(SEL)replacementMethodSelector;
@end
