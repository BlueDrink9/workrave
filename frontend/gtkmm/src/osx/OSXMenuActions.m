#import "OSXMenuActions.h"

@implementation OSXMenuActions

- (id)init:(OSXActionsRunner *)init_actionsRunner
{
  self = [super init];
  actionsRunner = init_actionsRunner;
  return self;
}

- (void) runAction: (id)sender
{
  NSLog(@"Contents of sender: %@", sender);
  NSLog(@"Command tag is: %ld\n", [sender tag]);
  actionsRunner->run_action([sender tag]);
}
@end
