#import <Cocoa/Cocoa.h>
#include "OSXActionsRunner.hh"

@interface OSXMenuActions: NSObject {
    OSXActionsRunner *actionsRunner;
}
-(id)init:(OSXActionsRunner *)init_actionsRunner;
-(void)runAction:(id)sender;
@end
