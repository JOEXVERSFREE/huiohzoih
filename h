
local lib = loadstring(game:HttpGet('https://raw.githubusercontent.com/cueshut/saves/main/criminality%20paste%20ui%20library'))()
local library = loadstring(game:HttpGet('https://raw.githubusercontent.com/JOETHEHACKER1/Lib/main/2.0'))()
local window = library.new('JoeX  |  Paid  |  v2.0  |  Beta', 'leadmarker')


--Tabs
---------------------------------------------------------------------------------------------------
local Tab1 = window.new_tab('rbxassetid://4483345998')
---------------------------------------------------------------------------------------------------


--Sections
---------------------------------------------------------------------------------------------------
local CombatSection = Tab1.new_section('Combats')
local VisualSection = Tab1.new_section('Visuals')
local MiscSection = Tab1.new_section('Misc')
---------------------------------------------------------------------------------------------------


--Sector
---------------------------------------------------------------------------------------------------
local LeftCombatSector = CombatSection.new_sector('Silent Aim', 'Left')
local LeftVisualSector = VisualSection.new_sector('Esp', 'Left')
local LeftMiscSector = MiscSection.new_sector('Esp', 'Left')
local RightVisualSector = VisualSection.new_sector('World', 'Right')
local RightCombatSector = CombatSection.new_sector('Gun Mods', 'Right')
local RightCombatSector2 = CombatSection.new_sector('Player', 'Right')
---------------------------------------------------------------------------------------------------


--Text ESP
---------------------------------------------------------------------------------------------------
-- Players </>

local player = game.Players.LocalPlayer
local character = game:GetService("Workspace").Ignore.FPSArms
local TextESPEnabled = false

local function updateDistanceLabel(v, TextLabel)
    if not character or not character.HumanoidRootPart then
        return
    end
    local distance = (v.Position - character.HumanoidRootPart.Position).Magnitude
    TextLabel.Text = "[" .. math.floor(distance) .. "m] Player"
end

player.CharacterAdded:Connect(function(newCharacter)
    character = newCharacter
end)

local function createESP(descendant)
    if descendant:IsA("Part") and descendant.Name == "Head" and descendant.CollisionGroupId == 2 then
        local BillboardGui = Instance.new("BillboardGui")
        local TextLabel = Instance.new("TextLabel")

        BillboardGui.Parent = descendant
        BillboardGui.AlwaysOnTop = true
        BillboardGui.LightInfluence = 1
        BillboardGui.Size = UDim2.new(0, 50, 0, 50)
        BillboardGui.StudsOffset = Vector3.new(0, 2, 0)
        BillboardGui.MaxDistance = 999

        TextLabel.Parent = BillboardGui
        TextLabel.BackgroundColor3 = Color3.new(1, 1, 1)
        TextLabel.BackgroundTransparency = 1
        TextLabel.Size = UDim2.new(0, 50, 0, 50)
        TextLabel.FontSize = 5
        TextLabel.TextColor3 = Color3.fromRGB(255, 255, 255)
        TextLabel.TextStrokeColor3 = Color3.fromRGB(94, 94, 94)
        TextLabel.Font = Enum.Font.SourceSansSemibold
        TextLabel.TextStrokeTransparency = 1
        TextLabel.TextScaled = false

        updateDistanceLabel(descendant, TextLabel)

        game:GetService("RunService").Heartbeat:Connect(function()
            if TextESPEnabled then
            updateDistanceLabel(descendant, TextLabel)
        end
    end)
end
end

local descendantConnection = nil

local function toggleESP()
    TextESPEnabled = not TextESPEnabled
    
    if TextESPEnabled then
        -- Create ESP for existing descendants
        for i, descendant in pairs(game.Workspace:GetDescendants()) do
            createESP(descendant)
        end
        
        -- Create ESP for new descendants
        descendantConnection = game.Workspace.DescendantAdded:Connect(function(descendant)
            createESP(descendant)
        end)
    else
        -- Destroy ESP for all descendants
        for _, descendant in pairs(game.Workspace:GetDescendants()) do
            if descendant:IsA("Part") and descendant.Name == "Head" and descendant.CollisionGroupId == 2 then
                local BillboardGui = descendant:FindFirstChild("BillboardGui")
                if BillboardGui and BillboardGui:IsDescendantOf(descendant) then
                    BillboardGui:Destroy()
                end
            end
        end

        -- Disconnect the DescendantAdded connection
        if descendantConnection then
            descendantConnection:Disconnect()
            descendantConnection = nil
        end
    end
end


local TextEspToggle = LeftVisualSector.element('Toggle', 'Text', false, function(v) --Text ESP toggle
    if v then
        toggleESP()
    end
end)
---------------------------------------------------------------------------------------------------


--No Recoil | Spread
---------------------------------------------------------------------------------------------------
local BowDerect = require(game.ReplicatedStorage.ItemConfigs.Bow)
local BlunderbussDerect = require(game.ReplicatedStorage.ItemConfigs.Blunderbuss)
local CrossbowDerect = require(game.ReplicatedStorage.ItemConfigs.Crossbow)
local USP9Derect = require(game.ReplicatedStorage.ItemConfigs.USP9)
local RPGDerect = require(game.ReplicatedStorage.ItemConfigs.RPG)
local M4A1Derect = require(game.ReplicatedStorage.ItemConfigs.M4A1)
local PipePistolDerect = require(game.ReplicatedStorage.ItemConfigs.PipePistol)
local PipeSMGDerect = require(game.ReplicatedStorage.ItemConfigs.PipeSMG)
function NoRecoilOff() --NoReCoil = Off
    BowDerect.HipRecoil = {
        rotMag = 0.05,
        rotSpeed = 3,
        push = 0.5,
        returnTime = 0.05,
        lerp = 0.9,
        returnLerp = 0.25,
        cameraY = 0.03,
        cameraX = 0.05,
        cameraXShake = 0.5
    }
    BowDerect.AimRecoil = {
        rotMag = 0.2,
        rotSpeed = 3,
        push = 0.5,
        returnTime = 0.05,
        lerp = 0.9,
        returnLerp = 0.25,
        cameraY = 0.03,
        cameraX = 0.05,
        cameraXShake = 0.5
    }
    BlunderbussDerect.HipRecoil = {
        rotMag = 0.05,
        rotSpeed = 3,
        push = 0.5,
        returnTime = 0.05,
        lerp = 0.9,
        returnLerp = 0.25,
        cameraY = 0.01,
        cameraX = 0.05,
        cameraXShake = 0.5
    }
    BlunderbussDerect.AimRecoil = {
        rotMag = 0.2,
        rotSpeed = 3,
        push = 0.5,
        returnTime = 0.05,
        lerp = 0.9,
        returnLerp = 0.25,
        cameraY = 0.01,
        cameraX = 0.05,
        cameraXShake = 0.5
    }
    CrossbowDerect.HipRecoil = {
        rotMag = 0.05,
        rotSpeed = 3,
        push = 0.5,
        returnTime = 0.05,
        lerp = 0.9,
        returnLerp = 0.25,
        cameraY = 0.03,
        cameraX = 0.05,
        cameraXShake = 0.5
    }
    CrossbowDerect.AimRecoil = {
        rotMag = 0.2,
        rotSpeed = 3,
        push = 0.5,
        returnTime = 0.05,
        lerp = 0.9,
        returnLerp = 0.25,
        cameraY = 0.03,
        cameraX = 0.05,
        cameraXShake = 0.5
    }
    USP9Derect.HipRecoil = {
        rotMag = 0.05,
        rotSpeed = 3,
        push = 0.5,
        returnTime = 0.05,
        lerp = 0.9,
        returnLerp = 0.25,
        cameraY = 0.01,
        cameraX = 0.05,
        cameraXShake = 0.5
    }
    USP9Derect.AimRecoil = {
        rotMag = 0.2,
        rotSpeed = 3,
        push = 0.5,
        returnTime = 0.05,
        lerp = 0.9,
        returnLerp = 0.25,
        cameraY = 0.01,
        cameraX = 0.05,
        cameraXShake = 0.5
    }
    RPGDerect.HipRecoil = {
        rotMag = 0.05,
        rotSpeed = 3,
        push = 0.5,
        returnTime = 0.05,
        lerp = 0.9,
        returnLerp = 0.25,
        cameraY = 0.01,
        cameraX = 0.05,
        cameraXShake = 0.5
    }
    RPGDerect.AimRecoil = {
        rotMag = 0.2,
        rotSpeed = 3,
        push = 0.5,
        returnTime = 0.05,
        lerp = 0.9,
        returnLerp = 0.25,
        cameraY = 0.01,
        cameraX = 0.05,
        cameraXShake = 0.5
    }
    M4A1Derect.HipRecoil = {
        rotMag = 0.05,
        rotSpeed = 3,
        push = 0.5,
        returnTime = 0.05,
        lerp = 0.9,
        returnLerp = 0.25,
        cameraY = 0.03,
        cameraX = 0.05,
        cameraXShake = 0.5
    }
    M4A1Derect.AimRecoil = {
        rotMag = 0.1,
        rotSpeed = 7,
        push = 0.5,
        returnTime = 0.05,
        lerp = 0.9,
        returnLerp = 0.25,
        cameraY = 0.02,
        cameraX = 0.03,
        cameraXShake = 0.5
    }
    PipePistolDerect.HipRecoil = {
        rotMag = 0.05,
        rotSpeed = 3,
        push = 0.5,
        returnTime = 0.05,
        lerp = 0.9,
        returnLerp = 0.25,
        cameraY = 0.01,
        cameraX = 0.05,
        cameraXShake = 0.5
    }
    PipePistolDerect.AimRecoil = {
        rotMag = 0.2,
        rotSpeed = 3,
        push = 0.5,
        returnTime = 0.05,
        lerp = 0.9,
        returnLerp = 0.25,
        cameraY = 0.01,
        cameraX = 0.05,
        cameraXShake = 0.5
    }
    PipeSMGDerect.HipRecoil = {
        rotMag = 0.05,
        rotSpeed = 3,
        push = 0.3,
        returnTime = 0.05,
        lerp = 0.9,
        returnLerp = 0.25,
        cameraY = 0.03,
        cameraX = 0.05,
        cameraXShake = 0.5
    }
    PipeSMGDerect.AimRecoil = {
        rotMag = 0.2,
        rotSpeed = 3,
        push = 0.3,
        returnTime = 0.05,
        lerp = 0.9,
        returnLerp = 0.25,
        cameraY = 0.03,
        cameraX = 0.05,
        cameraXShake = 0.5
    }
end

function NoRecoilOn() --NoReCoil = On
    BowDerect.HipRecoil = {
        rotMag = 0,
        rotSpeed = 0,
        push = 0,
        returnTime = 0,
        lerp = 0,
        returnLerp = 0,
        cameraY = 0,
        cameraX = 0,
        cameraXShake = 0
    }
    BowDerect.AimRecoil = {
        rotMag = 0,
        rotSpeed = 0,
        push = 0,
        returnTime = 0,
        lerp = 0,
        returnLerp = 0,
        cameraY = 0,
        cameraX = 0,
        cameraXShake = 0
    }
    BlunderbussDerect.HipRecoil = {
        rotMag = 0,
        rotSpeed = 0,
        push = 0,
        returnTime = 0,
        lerp = 0,
        returnLerp = 0,
        cameraY = 0,
        cameraX = 0,
        cameraXShake = 0
    }
    BlunderbussDerect.AimRecoil = {
        rotMag = 0,
        rotSpeed = 0,
        push = 0,
        returnTime = 0,
        lerp = 0,
        returnLerp = 0,
        cameraY = 0,
        cameraX = 0,
        cameraXShake = 0
    }
    CrossbowDerect.HipRecoil = {
        rotMag = 0,
        rotSpeed = 0,
        push = 0,
        returnTime = 0,
        lerp = 0,
        returnLerp = 0,
        cameraY = 0,
        cameraX = 0,
        cameraXShake = 0
    }
    CrossbowDerect.AimRecoil = {
        rotMag = 0,
        rotSpeed = 0,
        push = 0,
        returnTime = 0,
        lerp = 0,
        returnLerp = 0,
        cameraY = 0,
        cameraX = 0,
        cameraXShake = 0
    }
    USP9Derect.HipRecoil = {
        rotMag = 0,
        rotSpeed = 0,
        push = 0,
        returnTime = 0,
        lerp = 0,
        returnLerp = 0,
        cameraY = 0,
        cameraX = 0,
        cameraXShake = 0
    }
    USP9Derect.AimRecoil = {
        rotMag = 0,
        rotSpeed = 0,
        push = 0,
        returnTime = 0,
        lerp = 0,
        returnLerp = 0,
        cameraY = 0,
        cameraX = 0,
        cameraXShake = 0
    }
    RPGDerect.HipRecoil = {
        rotMag = 0,
        rotSpeed = 0,
        push = 0,
        returnTime = 0,
        lerp = 0,
        returnLerp = 0,
        cameraY = 0,
        cameraX = 0,
        cameraXShake = 0
    }
    RPGDerect.AimRecoil = {
        rotMag = 0,
        rotSpeed = 0,
        push = 0,
        returnTime = 0,
        lerp = 0,
        returnLerp = 0,
        cameraY = 0,
        cameraX = 0,
        cameraXShake = 0
    }
    M4A1Derect.HipRecoil = {
        rotMag = 0,
        rotSpeed = 0,
        push = 0,
        returnTime = 0,
        lerp = 0,
        returnLerp = 0,
        cameraY = 0,
        cameraX = 0,
        cameraXShake = 0
    }
    M4A1Derect.AimRecoil = {
        rotMag = 0,
        rotSpeed = 0,
        push = 0,
        returnTime = 0,
        lerp = 0,
        returnLerp = 0,
        cameraY = 0,
        cameraX = 0,
        cameraXShake = 0
    }
    PipePistolDerect.HipRecoil = {
        rotMag = 0,
        rotSpeed = 0,
        push = 0,
        returnTime = 0,
        lerp = 0,
        returnLerp = 0,
        cameraY = 0,
        cameraX = 0,
        cameraXShake = 0
    }
    PipePistolDerect.AimRecoil = {
        rotMag = 0,
        rotSpeed = 0,
        push = 0,
        returnTime = 0,
        lerp = 0,
        returnLerp = 0,
        cameraY = 0,
        cameraX = 0,
        cameraXShake = 0
    }
    PipeSMGDerect.HipRecoil = {
        rotMag = 0,
        rotSpeed = 0,
        push = 0,
        returnTime = 0,
        lerp = 0,
        returnLerp = 0,
        cameraY = 0,
        cameraX = 0,
        cameraXShake = 0
    }
    PipeSMGDerect.AimRecoil = {
        rotMag = 0,
        rotSpeed = 0,
        push = 0,
        returnTime = 0,
        lerp = 0,
        returnLerp = 0,
        cameraY = 0,
        cameraX = 0,
        cameraXShake = 0
    }
end

function NoSpreadOff() --NoSpread = Off
    BowDerect.Accuracy = 3000
    BlunderbussDerect.Accuracy = 1200
    CrossbowDerect.Accuracy = 5000
    USP9Derect.Accuracy = 5000
    RPGDerect.Accuracy = 7000
    M4A1Derect.Accuracy = 7000
    PipePistolDerect.Accuracy = 4000
    PipeSMGDerect.Accuracy = 5000
end

function NoSpreadOn() --NoSpread = on
    BowDerect.Accuracy = 9999999
    BlunderbussDerect.Accuracy = 9999999
    CrossbowDerect.Accuracy = 9999999
    USP9Derect.Accuracy = 9999999
    RPGDerect.Accuracy = 9999999
    M4A1Derect.Accuracy = 9999999
    PipePistolDerect.Accuracy = 9999999
    PipeSMGDerect.Accuracy = 9999999
end


local GunMods = false
local function GunModsCheck()
    if GunMods == false then
        GunMods = true
    elseif GunMods == true then
        GunMods = false
    end
    if GunMods == true then
        NoRecoilOn()
        NoSpreadOn()
    elseif GunMods == false then
        NoRecoilOff()
        NoSpreadOff()
    end
end
local GunModsToggle = RightCombatSector.element('Toggle', 'No Recoil | Spread', false, function(v) --No Recoil | Spread Button
    if v then
        GunModsCheck()
    end
end)
---------------------------------------------------------------------------------------------------


--World
---------------------------------------------------------------------------------------------------
local GrassButton = RightVisualSector.element('Button', 'Remove Grass', nil, function() --Grass Button
    sethiddenproperty(game.Workspace.Terrain, "Decoration", GrassRemove)
end)
---------------------------------------------------------------------------------------------------


--HitBox Expender
---------------------------------------------------------------------------------------------------
local HitBX = 1.2
local HitBY = 3.5
local HitBZ = 1.5

local EnableHBB = false
local function HitBoxExtender()
    if EnableHBB == false then
        EnableHBB = true
    elseif EnableHBB == true then
        EnableHBB = false
    end
    if EnableHBB == true then
        for v, i in pairs(workspace:GetChildren()) do
            if i:FindFirstChild("HumanoidRootPart") then
                i.Head.Size = Vector3.new(HitBX, HitBY, HitBZ)
            end
        end
        game.ReplicatedStorage.Player.Head.Size = Vector3.new(HitBX, HitBY, HitBZ)
    elseif EnableHBB == false then
        for v, i in pairs(workspace:GetChildren()) do
            if i:FindFirstChild("HumanoidRootPart") then
                i.Head.Size = Vector3.new(1.9362, 0.9681, 0.9681)
            end
        end
        game.ReplicatedStorage.Player.Head.Size = Vector3.new(1.9362, 0.9681, 0.9681)
    end
end

local HitBoxExtenderToggle = RightCombatSector2.element('Toggle', 'HitBox Extender', false, function(v) --No Recoil | Spread Button
    if v then
        HitBoxExtender()
    end
end)
---------------------------------------------------------------------------------------------------


--Chams
---------------------------------------------------------------------------------------------------
local Chams = false

local function runChams()
    while Chams == true do
    wait(0.1)
    for i, a in ipairs(workspace:GetChildren()) do
        if a:FindFirstChild("HumanoidRootPart") then
            if not a:FindFirstChild("Chams") then
                if a ~= game:GetService("Workspace").Ignore.FPSArms then
                    local b = Instance.new("Highlight", a)
                    b.Adornee = a
                    b.Name = "Chams"
                    b.FillColor = Color3.fromRGB(128, 187, 219)
                    b.FillTransparency = 0.6
                    b.OutlineColor = Color3.fromRGB(13, 105, 172)
                end
            end
        end
    end
end
end


local function ChamsDisabled()
    for _, a in ipairs(workspace:GetChildren()) do
        local b = a:FindFirstChild("Chams")
        if b and b:IsA("Highlight") then
                b:Destroy()
        end
    end
end

local function ChamsEnabled()
    if Chams == false then
        Chams = true
    elseif Chams == true then
        Chams = false
    end
    if Chams == true then
        print("Chams on")
        runChams()
    elseif Chams == false then
        print("Chams off")
        ChamsDisabled()
    end
end

local ChamsToggle = LeftVisualSector.element('Toggle', 'Chams', false, function(v) --Chams Toggle
    if v then
        ChamsEnabled()
    end
 end)
---------------------------------------------------------------------------------------------------


--Crosshair
---------------------------------------------------------------------------------------------------
local crosshairEnabled = false
local crosshairDrawing = {}
local function drawCrosshair()
    local cam = workspace.CurrentCamera or workspace:FindFirstChildOfClass("Camera")
    if not cam then
        return
    end
    
    local settings = {
        color = Color3.fromRGB(255, 0, 255), -- Crosshair color set to purple
        thickness = 2,
        length = 8,
        opacity = 1,
        x_offset = 0,
        y_offset = 0,
        recenter = true
    }
    
    local center = Vector2.new(cam.ViewportSize.x / 2, cam.ViewportSize.y / 2)
    local crosshairLines = {
        {From = center - Vector2.new(settings.length, 0) - Vector2.new(settings.x_offset, settings.y_offset), To = center + Vector2.new(settings.length, 0) - Vector2.new(settings.x_offset, settings.y_offset)},
        {From = center - Vector2.new(0, settings.length) - Vector2.new(settings.x_offset, settings.y_offset), To = center + Vector2.new(0, settings.length) - Vector2.new(settings.x_offset, settings.y_offset)}
    }
    
    for i, line in ipairs(crosshairLines) do
        if not crosshairDrawing[i] then
            crosshairDrawing[i] = Drawing.new("Line")
        end
        
        crosshairDrawing[i].From = line.From
        crosshairDrawing[i].To = line.To
        crosshairDrawing[i].Thickness = settings.thickness
        crosshairDrawing[i].Color = settings.color
        crosshairDrawing[i].Transparency = settings.opacity
        crosshairDrawing[i].Visible = crosshairEnabled
    end
    
    if settings.recenter then
        if not crosshairDrawing.connection then
            crosshairDrawing.connection = cam:GetPropertyChangedSignal("ViewportSize"):Connect(function()
                drawCrosshair()
            end)
        end
    else
        if crosshairDrawing.connection then
            crosshairDrawing.connection:Disconnect()
            crosshairDrawing.connection = nil
        end
    end
end

game:GetService("RunService").RenderStepped:Connect(function()
    drawCrosshair()
end)

local function loadCrosshair()
    crosshairEnabled = true
    for _, drawing in ipairs(crosshairDrawing) do
        drawing.Visible = crosshairEnabled
    end
end

local function unloadCrosshair()
    crosshairEnabled = false
    for _, drawing in ipairs(crosshairDrawing) do
        drawing.Visible = crosshairEnabled
    end
end


--
local Crosshair = false

local function CrosshairToggle()
    if Crosshair == false then
        Crosshair = true
    elseif Crosshair == true then
        Crosshair = false
    end
    if Crosshair == true then
        print("Crosshair on")
        loadCrosshair()
    elseif Crosshair == false then
        print("Crosshair off")
        unloadCrosshair()
    end
end

local CrosshairToggle = LeftMiscSector.element('Toggle', 'Crosshair', false, function(v) --Crosshair Toggle
    if v then
        CrosshairToggle()
    end
 end)

 unloadCrosshair()
---------------------------------------------------------------------------------------------------
