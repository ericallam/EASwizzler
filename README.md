EASwizzler
=========

EASwizzler is an Objective-C class used for easy Method Swizzling, and it even supports swizzling methods on classes that are apart of a Class Cluster like NSArray and NSString.

Usage
======

[Method Swizzling](http://cocoadev.com/wiki/MethodSwizzling) is a well worn technique for swapping method implementations, allowing you to modify methods in code you don't have access to, like Foundation or Cocoa.

For example, let's say you want to modify NSArray's `lastObject` method to log a message every time it was called.  The first step is to create your own method implementation that has as different selector but conforms to the same return type and arguments. Create the custom method on a Category of NSArray, like this:

```objc
@interface NSArray (CustomLastObject)
- (id)custom_lastObject;
@end

@implementation NSArray (CustomLastObject)
- (id)custom_lastObject {
  NSLog(@"lastObject was sent to %@", self);
  return [self custom_lastObject];
}
@end
```

Notice how inside of the `custom_lastObject` implementation, we are returning the result of `[self custom_lastObject]`.  That's because after the swizzling occurs, the original implementation of `lastObject` will still be accessible by sending `custom_lastObject`.  

Now we use EASwizzler to swizzle the class of an instance of `NSArray`:

```objc
[EASwizzler swizzleClassOfInstance:[[NSArray alloc] init]
                     replaceMethod:@selector(lastObject)
                       withMethod:@selector(custom_lastObject)];
```

The reason we use `swizzleClassOfInstance:replaceMethod:withMethod:` instead of `swizzleClass:replaceMethod:withMethod` is because `NSArray` is apart of a class cluster and `[[[NSArray alloc] init] class]` isn't an `NSArray`, but `__NSArrayI`, so just trying to swizzle the `NSArray` class won't work.  

Always use `swizzleClassOfInstance` with objects like NSString and NSArray.  For almost everything else you can just use `swizzleClass`.

Contributing
============

Pull requests are always welcome. There are no tests so don't worry about that ;)

License
=======

MIT


Authors
========

Eric Allam
