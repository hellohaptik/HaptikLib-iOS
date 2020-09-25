

Pod::Spec.new do |s|

  s.name         = "HaptikLib"
  s.version      = "2.6.4"
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
  s.ios.preserve_paths = '**'
  s.default_subspec = 'Core'
  
  s.pod_target_xcconfig = {
    'VALID_ARCHS' => 'x86_64 armv7 arm64',
  }

  # Haptik Core Module Subspec
  s.subspec 'Core' do |core|
    core.ios.deployment_target = '9.0'
    core.dependency    'HaptikLib/Base'
    core.vendored_frameworks = "Frameworks/Core/HaptikLib.framework"
  end

  # Haptik Base Module Subspec
  s.subspec 'Base' do |base|
    base.ios.deployment_target = '9.0'
    base.dependency    'PINRemoteImage', '3.0.1'
    base.dependency    'PINRemoteImage/WebP', '3.0.1'
    base.vendored_frameworks = "Frameworks/Base/HaptikBase.framework"
  end

  # Haptik Location Module Subspec
  s.subspec 'Location' do |location|
    location.ios.deployment_target = '10.0'
    location.vendored_frameworks = "Frameworks/Location/HaptikLocation.framework"
  end

  # Haptik Speech Module Subspec
  s.subspec 'Speech' do |speech|
    speech.ios.deployment_target = '10.0'
    speech.frameworks = 'AudioToolbox', 'AVFoundation', 'Speech'
    speech.vendored_frameworks = "Frameworks/Speech/HaptikSpeech.framework"
  end
  
  # Haptik Offline Module Subspec
  s.subspec 'Offline' do |offline|
    offline.ios.deployment_target = '9.0'
    offline.library = 'c++'
    offline.vendored_frameworks = "Frameworks/Offline/HaptikOffline.framework"
  end
  
  # Haptik Analytics Module Subspec
  s.subspec 'Analytics' do |analytics|
    analytics.ios.deployment_target = '9.0'
    analytics.vendored_frameworks = "Frameworks/Analytics/HaptikAnalytics.framework"
  end
end
