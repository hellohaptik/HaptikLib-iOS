

Pod::Spec.new do |s|

  s.name         = "HaptikLib"
  s.version      = "1.4.1"
  s.summary      = "Say goodbye to App Fatigue. Instantly enable 100+ chatbots across various daily tasks"

  s.description  = <<-DESC
                The mobile app industry is about a decade old but publishers are still trying to figure out hacks to improve user retention. App fatigue is not just a theory any more: 60% of apps are uninstalled within the first week. The Haptik Assistant SDK enables a layer of daily use chatbots in any mobile app. Instantly provide a lot more reasons for users to keep using your app. You can also monetize through transactions and the Haptik ads platform.
                   DESC

  s.homepage     = "https://github.com/hellohaptik/HaptikLib-iOS"
  s.license      = { :type => "Commercial", :file => "LICENSE" }
  s.authors      = { 'Simranjot Singh' => 'simranjyot@haptik.ai' }
  s.social_media_url   = "https://twitter.com/haptik"

  s.ios.deployment_target = '9.0'
  s.requires_arc = true
  s.source       = { :git => "https://github.com/hellohaptik/HaptikLib-iOS.git", :tag => s.version.to_s }

  s.frameworks =  'Accelerate', 'CoreGraphics', 'CoreLocation', 'CoreTelephony', 'CoreText', 'OpenGLES', 'QuartzCore', 'SystemConfiguration', 'UIKit'

  s.vendored_frameworks = 'Frameworks/Core/HaptikLib.framework'
  s.source_files = "Frameworks/Core/HaptikLib.framework/Headers/*.h"
  s.public_header_files = "Frameworks/Core/HaptikLib.framework/Headers/*.h"
  s.ios.preserve_paths = '**'

  s.default_subspec = 'Base'

  # Haptik Base Module Subspec

  s.subspec 'Base' do |base|
    base.ios.deployment_target = '9.0'
    base.vendored_frameworks = "Frameworks/Base/HaptikBase.framework"
    base.source_files = "Frameworks/Base/HaptikBase.framework/Headers/*.h"
    base.public_header_files = "Frameworks/Base/HaptikBase.framework/Headers/*.h"

    base.dependency    'PINRemoteImage', '3.0.0-beta.13'
    base.dependency    'PINRemoteImage/WebP', '3.0.0-beta.13'
  end

  s.dependency    'PayUIndia-Custom-Browser', '5.8.1'
  s.dependency    'GoogleMaps'
  s.dependency    'GooglePlaces'
  s.dependency    'GooglePlacePicker'

end
