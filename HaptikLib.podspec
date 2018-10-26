

Pod::Spec.new do |s|

  s.name         = "HaptikLib"
  s.version      = "1.3.0"
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
  s.vendored_frameworks = 'Framework/HaptikLib.framework'
  s.ios.preserve_paths = '**'
  s.dependency    'PINRemoteImage', '3.0.0-beta.13'
  s.dependency    'PINRemoteImage/WebP', '3.0.0-beta.13'
  s.dependency    'PayUIndia-Custom-Browser'
  s.dependency    'GoogleMaps'
  s.dependency    'GooglePlaces'
  s.dependency    'GooglePlacePicker'

end
